//
// Created by romain on 11/04/2021.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H


#include <string>
#include <vector>
#include <memory>
#include "Transaction.h"
#include "Block.h"

using namespace std;

class Blockchain {
private:
    shared_ptr<vector<Transaction>> mTransactions;
    vector<shared_ptr<Block>> mChain;

public:
    Blockchain();
    Blockchain(const Blockchain& other) = delete;
    void operator=(const Blockchain& other) = delete;

    /**
     * Create a new transaction to go into the next mined Block
     * @param sender Address of sender
     * @param recipient Address of recipient
     * @param amount Amount
     * @return The index of the block holding the transaction
     */
    int addTransaction(const Transaction& transaction);

    shared_ptr<Block> newBlock(unsigned int proof, const string& previousHash = nullptr);
};


#endif //BLOCKCHAIN_BLOCKCHAIN_H
