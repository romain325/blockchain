//
// Created by romain on 11/04/2021.
//

#include "Blockchain.h"

int Blockchain::addTransaction(const Transaction& transaction) {
    this->mTransactions->push_back(transaction);
    return this->mTransactions->size();
}

shared_ptr<Block> Blockchain::newBlock(unsigned int proof, const string& previousHash) {
    auto block = make_shared<Block>(
            this->mChain.size() +1,
            time(nullptr),
            *this->mTransactions,
            proof,
            previousHash.empty() ? previousHash : "test"
    );

    this->mTransactions->clear();
    this->mChain.push_back(block);
    return block;
}

Blockchain::Blockchain() {
    this->newBlock(100,"1");
}
