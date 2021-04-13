//
// Created by romain on 13/04/2021.
//

#ifndef BLOCKCHAIN_CHAINCONTROLLER_H
#define BLOCKCHAIN_CHAINCONTROLLER_H


#include "../RestController.h"

class ChainController : public RestController{
public:
    ChainController() : RestController("/chain") {};
    void setupRoutes(Rest::Router *router) override;

protected:
    void mine(const Rest::Request& req, Http::ResponseWriter rep);
    void chainInfos(const Rest::Request& req, Http::ResponseWriter rep);
};


#endif //BLOCKCHAIN_CHAINCONTROLLER_H
