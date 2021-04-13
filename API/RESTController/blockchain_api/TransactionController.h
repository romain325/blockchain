//
// Created by romain on 13/04/2021.
//

#ifndef BLOCKCHAIN_TRANSACTIONCONTROLLER_H
#define BLOCKCHAIN_TRANSACTIONCONTROLLER_H


#include "../RestController.h"

class TransactionController : public RestController {
public:
    TransactionController() : RestController("/transaction") {};
    void setupRoutes(Rest::Router *router) override;

protected:
    void new_transaction(const Rest::Request& req, Http::ResponseWriter rep);
};


#endif //BLOCKCHAIN_TRANSACTIONCONTROLLER_H
