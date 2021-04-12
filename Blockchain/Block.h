#include <utility>

//
// Created by romain on 11/04/2021.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

struct Block {
    Block(unsigned int index, unsigned long timestamp, std::vector<Transaction> transactions, unsigned int proof, std::string previousHash)
          : index(index), timestamp(timestamp), transactions(std::move(transactions)), proof(proof), previous_hash(std::move(previousHash)) {}

    unsigned int index;
    unsigned long timestamp;
    std::vector<Transaction> transactions;
    unsigned int proof;
    std::string previous_hash;
};

#endif //BLOCKCHAIN_BLOCK_H
