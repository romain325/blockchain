//
// Created by romain on 11/04/2021.
//
#include <gtest/gtest.h>
#include "../Blockchain/Blockchain.h"

using namespace bc;

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


TEST(BlockChainTest, JSONTest){
    Transaction transaction = {"me","patrick",5};
    Block block(1u,213546lu,std::vector<Transaction>(),2135u,"previousHash");

    json j = transaction;
    json j2 = block;
    std::cout << j << std::endl;
    std::cout << j2 << std::endl;
}


TEST(BlockChainTest, SHA256Test){
    Blockchain bc;
    json j = *bc.last();
    cout << j.dump().c_str() << endl;
    cout << Blockchain::getHash(bc.last().get()) << endl;
}