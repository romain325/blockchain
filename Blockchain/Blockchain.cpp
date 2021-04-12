//
// Created by romain on 11/04/2021.
//

#include "Blockchain.h"
#include <openssl/sha.h>
#include <iostream>
#include <sstream>

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
    json j = *block;
    unsigned char hash[SHA512_DIGEST_LENGTH];
    char result[128];

    SHA512(reinterpret_cast<const unsigned char*>(j.dump().c_str()), strlen(j.dump().c_str()), hash);

    for(int i = 0; i < SHA512_DIGEST_LENGTH; i++){
        sprintf(result + (i * 2), "%02x", hash[i]);
    }
    return std::string(result);
}
