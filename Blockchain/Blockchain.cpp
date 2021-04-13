//
// Created by romain on 11/04/2021.
//

#include "Blockchain.h"
#include <iostream>
using namespace bc;

int Blockchain::addTransaction(const Transaction& transaction) {
    this->mTransactions.push_back(transaction);
    return this->mTransactions.size();
}


shared_ptr<Block> Blockchain::newBlock(unsigned int proof, const string& previousHash) {
    auto block = make_shared<Block>(
            this->mChain.size() +1,
            time(nullptr),
            this->mTransactions,
            proof,
            previousHash.empty() ? previousHash : "test"
    );

    this->mTransactions.clear();
    this->mChain.push_back(block);
    return block;
}

Blockchain::Blockchain() {
    this->newBlock(100,"1");
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
