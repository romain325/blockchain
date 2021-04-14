//
// Created by romain on 11/04/2021.
//
#include <gtest/gtest.h>
#include "../Blockchain/Blockchain.h"
#include "../Blockchain/ProofOfWork.h"

using namespace bc;

TEST(BlockChainTest, AddTransaction){
    Blockchain chain;
    int size = chain.addTransaction(Transaction("test","test",1));
    ASSERT_EQ(size, 1) << "The chain hasn't grown";
}

TEST(BlockChainTest, NewBlock){
    Blockchain chain;
    auto block = chain.newBlock("12");
    ASSERT_EQ(block->proof,200) << "Proof unexact";
}


TEST(BlockChainTest, JSONTest){
    Blockchain bc;
    Transaction transaction = {"me","patrick",5};
    Block block(1u,213546lu,std::vector<Transaction>(),"previousHash");

    json j = transaction;
    json j2 = block;
    json j3 = bc.getAsJson();
    std::cout << j << std::endl;
    std::cout << j2 << std::endl;
    std::cout << j3 << std::endl;
}

TEST(BlockChainTest, SHA256Test){
    Blockchain bc;
    json j = *bc.last();
    cout << j.dump().c_str() << endl;
    cout << bc.last()->hash() << endl;
}

TEST(BlockChainTest, ProofTest){
    auto block = make_shared<Block>(1u,213546lu,std::vector<Transaction>(),"previousHash");
    ProofOfWork::proofOfWork(block);
    for (int i = 0; i < ProofOfWork::DIFFICULTY; ++i) {
        ASSERT_TRUE(block->hash()[i] == '6');
    }
}

TEST(BlockChainTest, GenesisBlock){
    Blockchain bc;
    ASSERT_TRUE(ProofOfWork::validProof(bc.last()->hash()));
}
