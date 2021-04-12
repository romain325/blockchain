//
// Created by romain on 11/04/2021.
//

#ifndef BLOCKCHAIN_RESTCONTROLLER_H
#define BLOCKCHAIN_RESTCONTROLLER_H

#include <pistache/router.h>

#include <utility>

using namespace Pistache;

class RestController {
private:

public:
    explicit RestController(std::string requestMapping) : m_requestMapping(std::move(requestMapping)) {};
    virtual void setupRoutes(Rest::Router* router) = 0;

protected:
    std::string m_requestMapping;

};


#endif //BLOCKCHAIN_RESTCONTROLLER_H
