//
// Created by romain on 17/04/2021.
//

#include "NodesController.h"
#include "../../../Blockchain/Node.h"
#include "../../../Blockchain/Blockchain.h"

extern bc::Blockchain blockchain;

void NodesController::setupRoutes(Rest::Router *router) {
    Pistache::Rest::Routes::Post(*router, this->m_requestMapping + "/register", Pistache::Rest::Routes::bind(&NodesController::registerNode, this));
    Pistache::Rest::Routes::Get(*router, this->m_requestMapping + "/resolve", Pistache::Rest::Routes::bind(&NodesController::resolveConflicts, this));
}

void NodesController::resolveConflicts(const Rest::Request &req, Http::ResponseWriter rep) {
    blockchain.consensusAlgorithm();
    rep.send(Http::Code::Ok, to_string(true));
}

void NodesController::registerNode(const Rest::Request &req, Http::ResponseWriter rep) {
    json data = std::string(req.body().begin(), req.body().end());
    std::vector<bc::Node> nodes = data["nodes"];

    for(const auto& node: nodes){
        blockchain.registerNode(node.getHost());
    }

    json message;
    message["message"] = "You should resolve your chain now";

    rep.send(Http::Code::Ok, message.dump());
}
