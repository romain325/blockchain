//
// Created by romain on 13/04/2021.
//

#include "TransactionController.h"
#include "../../../Blockchain/Blockchain.h"

extern bc::Blockchain blockchain;

void TransactionController::setupRoutes(Rest::Router *router) {
    Pistache::Rest::Routes::Post(*router, this->m_requestMapping + "/new", Pistache::Rest::Routes::bind(&TransactionController::new_transaction, this));
}

void TransactionController::new_transaction(const Rest::Request &req, Http::ResponseWriter rep) {
    json body = json::parse(req.body());
    if(!body.contains("sender") || !body.contains("recipient") || !body.contains("amount")){
        rep.send(Http::Code::Bad_Request, "Missing values");
    }
    int index = blockchain.addTransaction(bc::Transaction(body["sender"], body["recipient"], body["amount"].get<int>()));
    json message;
    message["message"] = "Transaction added to block n°" + to_string(blockchain.last()->index +1) + ", transaction n°" + to_string(index);
    rep.send(Http::Code::Ok, message.dump());
}
