//
// Created by romain on 11/04/2021.
//

#include "Blockchain.h"
#include "ProofOfWork.h"
#include "../API/Utils/Uri.h"
#include "../API/Utils/HTTPRequest.hpp"
#include <iostream>
#include <utility>
using namespace bc;

int Blockchain::addTransaction(const Transaction& transaction) {
    this->mTransactions.push_back(transaction);
    return this->mTransactions.size();
}


shared_ptr<Block> Blockchain::newBlock(const string& previousHash) {
    auto block = make_shared<Block>(
            this->mChain.size(),
            time(nullptr),
            this->mTransactions,
            previousHash.empty() ? "666" : previousHash
    );

    this->mTransactions.clear();
    this->mChain.push_back(block);
    return block;
}

Blockchain::Blockchain() : mNodes(unordered_set<Node>()){
    auto genesis = make_shared<Block>(0u,666ul,std::vector<Transaction>(), "666");
    ProofOfWork::proofOfWork(genesis);

    this->mChain.push_back(genesis);
}


shared_ptr<Block> Blockchain::last() {
    return this->mChain.back();
}

json Blockchain::getAsJson() {
    vector<Block> copy;
    for (auto it = this->mChain.begin(); it != mChain.end() ; it++) {
        copy.push_back(**it);
    }
    json j;
    j["chain"] = copy;
    j["length"] = this->mChain.size();
    return j;
}

vector<shared_ptr<Block>> Blockchain::getFromJson(json data) {
    vector<shared_ptr<Block>> val;
    for(json j : data){
        val.push_back(make_shared<Block>(j.get<Block>()));
    }
    return val;
}

shared_ptr<Block> Blockchain::mine() {
    this->addTransaction(bc::Transaction("666", ProofOfWork::getUuid(), 1));
    auto block = this->newBlock(this->last()->hash());
    ProofOfWork::proofOfWork(block);
    return block;
}

void Blockchain::registerNode(const string & node_address) {
    this->mNodes.insert(Node(node_address));
}

bool Blockchain::isChainValid(Blockchain &chain) {
    for (int i = 1; i < chain.last()->index; i++) {
        if(chain[i]->previous_hash != chain[i-1]->hash() || ProofOfWork::validProof(chain[i]->hash())){
            return false;
        }
    }
    return true;
}

shared_ptr<Block> Blockchain::operator[](const int i) {
    return this->mChain[i];
}

void Blockchain::consensusAlgorithm() {
    int max = this->mChain.size();

    for(Node node : this->mNodes){
        // HTTP REQUESTS
        http::Request request { "http://"+ node.getHost() + "/chain" };
        const auto res = request.send("GET");
        if(res.status == 200){
            const json data = std::string {res.body.begin(), res.body.end()};
            if(data["length"] > max){
                max = data["length"];
                this->mChain = getFromJson(data["chain"]);
            }
        }
    }
}



