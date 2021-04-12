//
// Created by romain on 11/04/2021.
//

#ifndef BLOCKCHAIN_STATUSCONTROLLER_H
#define BLOCKCHAIN_STATUSCONTROLLER_H


#include "RestController.h"

class StatusController : public RestController {
public:
    StatusController() : RestController("/status"){};
    void setupRoutes(Rest::Router *router) override;

protected:
    void helloworld(const Rest::Request& req, Http::ResponseWriter rep);
};


#endif //BLOCKCHAIN_STATUSCONTROLLER_H
