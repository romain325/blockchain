//
// Created by romain on 13/04/2021.
//

#include "ChainController.h"
#include "../../../Blockchain/Blockchain.h"
#include "../../../Blockchain/ProofOfWork.h"

extern bc::Blockchain blockchain;

void ChainController::setupRoutes(Rest::Router *router) {
    Pistache::Rest::Routes::Get(*router, this->m_requestMapping + "/", Pistache::Rest::Routes::bind(&ChainController::chainInfos, this));
    Pistache::Rest::Routes::Get(*router, this->m_requestMapping + "/mine", Pistache::Rest::Routes::bind(&ChainController::mine, this));
}

void ChainController::chainInfos(const Rest::Request& req, Http::ResponseWriter rep) {
    rep.send(Http::Code::Ok, blockchain.getAsJson().dump());
}

void ChainController::mine(const Rest::Request& req, Http::ResponseWriter rep) {
    int lastProof = blockchain.last()->proof;
    int proof = ProofOfWork::proofOfWork(lastProof);

    blockchain.addTransaction(bc::Transaction("0", ProofOfWork::getUuid(), 1));

    shared_ptr<bc::Block> block = blockchain.newBlock(proof, blockchain.getHash(blockchain.last().get()));

    json resp;
    resp["message"] = "Block Forged";
    resp["block"] = *block;

    rep.send(Http::Code::Ok, resp.dump());
}
