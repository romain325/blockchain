//
// Created by romain on 11/04/2021.
//
#include <gtest/gtest.h>
#include "../Blockchain/Blockchain.h"
#include "../Blockchain/ProofOfWork.h"
#include "../API/Utils/Uri.h"

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

TEST(UtilsTest, URIParser){
    Uri u[] {
            Uri::Parse(L"http://localhost:80/foo.html?&q=1:2:3"),
            Uri::Parse(L"https://localhost:80/foo.html?&q=1"),
            Uri::Parse(L"localhost/foo"),
            Uri::Parse(L"https://localhost/foo"),
            Uri::Parse(L"localhost:8080"),
            Uri::Parse(L"localhost?&foo=1"),
            Uri::Parse(L"localhost?&foo=1:2:3")
    };

    for(int i = 0; i < 7; i++){
        cout << u[i].Protocol << u[i].Host << u[i].Port << u[i].Path << u[i].QueryString <<endl;
        ASSERT_EQ(u[i].Host, "localhost");
    }
}

TEST(BlockChainTest, ChainSerialization){
    const json data = Blockchain().getAsJson();
    shared_ptr<Block> b = Blockchain::getFromJson(data["chain"])[0];
    cout << b->previous_hash << endl;
    cout << b->index << " " << b->hash() << b->timestamp << endl;
}