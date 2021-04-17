//
// Created by romain on 11/04/2021.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H


#include <string>
#include <vector>
#include <memory>
#include <unordered_set>
#include "Block.h"
#include "Node.h"
#include "../API/Utils/Uri.h"

using namespace std;

namespace bc {
    class Blockchain {
    private:
        vector<Transaction> mTransactions;
        vector<shared_ptr<Block>> mChain;
        unordered_set<Node> mNodes;

    public:
        Blockchain();

        Blockchain(const Blockchain &other) = delete;

        void operator=(const Blockchain &other) = delete;

        shared_ptr<Block> operator[](int i);

        /**
         * Create a new transaction to go into the next mined Block
         * @param sender Address of sender
         * @param recipient Address of recipient
         * @param amount Amount
         * @return The index of the block holding the transaction
         */
        int addTransaction(const Transaction &transaction);

        shared_ptr<Block> newBlock(const string &previousHash = nullptr);

        shared_ptr<Block> last();

        shared_ptr<Block> mine();

        void registerNode(const string& node_address);

        /**
         * Keep the longest chain of the nodes
         * @return has been replaced
         */
        void consensusAlgorithm();

        static bool isChainValid(Blockchain& chain);

        json getAsJson();
        static vector<shared_ptr<Block>> getFromJson(json data);
    };
}

#endif //BLOCKCHAIN_BLOCKCHAIN_H
