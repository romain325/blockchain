//
// Created by romain on 11/04/2021.
//

#include "Blockchain.h"
#include "ProofOfWork.h"
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

Blockchain::Blockchain() {
    auto genesis = make_shared<Block>(0u,666ul,std::vector<Transaction>(), "666");
    ProofOfWork::proofOfWork(genesis);

    this->mChain.push_back(genesis);
}


shared_ptr<Block> Blockchain::last() {
    return this->mChain.back();
}


std::string Blockchain::getHash(Block* block) {
    return block->hash();
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

shared_ptr<Block> Blockchain::mine() {
    this->addTransaction(bc::Transaction("666", ProofOfWork::getUuid(), 1));
    auto block = this->newBlock(this->last()->hash());
    ProofOfWork::proofOfWork(block);
    return block;
}
