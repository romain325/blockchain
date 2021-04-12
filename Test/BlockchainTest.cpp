//
// Created by romain on 11/04/2021.
//
#include <gtest/gtest.h>
#include "../Blockchain/Blockchain.h"

TEST(BlockChainTest, AddTransaction){
    Blockchain chain;
    int size = chain.addTransaction(Transaction("test","test",1));
    ASSERT_EQ(size, 1) << "The chain hasn't grown";
}

TEST(BlockChainTest, NewBlock){
    Blockchain chain;
    auto block = chain.newBlock(200,"12");
    ASSERT_EQ(block->proof,200) << "Proof unexact";
}