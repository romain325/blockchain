//
// Created by romain on 17/04/2021.
//

#ifndef BLOCKCHAIN_NODESCONTROLLER_H
#define BLOCKCHAIN_NODESCONTROLLER_H


#include "../RestController.h"

class NodesController : public RestController{
public:
    NodesController() : RestController("/nodes") {};
    void setupRoutes(Rest::Router *router) override;

protected:
    void registerNode(const Rest::Request& req, Http::ResponseWriter rep);
    void resolveConflicts(const Rest::Request& req, Http::ResponseWriter rep);
};


#endif //BLOCKCHAIN_NODESCONTROLLER_H
