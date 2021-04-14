//
// Created by romain on 11/04/2021.
//


#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <utility>

#include "Transaction.h"

namespace bc {
    struct Block {
        Block() = default;
        Block(unsigned int index, unsigned long timestamp, std::vector<Transaction> transactions, std::string previousHash)
                : index(index), timestamp(timestamp), transactions(std::move(transactions)), proof(0), previous_hash(std::move(previousHash)) {}

        unsigned int index;
        unsigned long timestamp;
        std::vector<Transaction> transactions;
        unsigned int proof;
        std::string previous_hash;

        std::string hash();
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Block, index, timestamp, transactions, proof, previous_hash);
}
#endif //BLOCKCHAIN_BLOCK_H
