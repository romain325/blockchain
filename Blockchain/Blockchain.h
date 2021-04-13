//
// Created by romain on 11/04/2021.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H


#include <string>
#include <vector>
#include <memory>
#include "Block.h"

using namespace std;

namespace bc {
    class Blockchain {
    private:
        vector<Transaction> mTransactions;
        vector<shared_ptr<Block>> mChain;

    public:
        Blockchain();

        Blockchain(const Blockchain &other) = delete;

        void operator=(const Blockchain &other) = delete;

        /**
         * Create a new transaction to go into the next mined Block
         * @param sender Address of sender
         * @param recipient Address of recipient
         * @param amount Amount
         * @return The index of the block holding the transaction
         */
        int addTransaction(const Transaction &transaction);

        shared_ptr<Block> newBlock(unsigned int proof, const string &previousHash = nullptr);

        shared_ptr<Block> last();

        static std::string getHash(Block* block);

        json getAsJson();
    };
}

#endif //BLOCKCHAIN_BLOCKCHAIN_H
