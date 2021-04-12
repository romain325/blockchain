//
// Created by romain on 11/04/2021.
//

#ifndef BLOCKCHAIN_ROUTERSERVICE_H
#define BLOCKCHAIN_ROUTERSERVICE_H

#include <pistache/router.h>
#include "../RESTController/RestController.h"

using namespace Pistache;

class RouterService {
private:
    Rest::Router m_router;

public:
    RouterService() : m_router(Rest::Router()){};

    RouterService(RouterService &other) = delete;
    void operator=(const RouterService&) = delete;

    std::shared_ptr<Pistache::Rest::Private::RouterHandler> getHandler() const;
    void addController(RestController& controller);
};



#endif //BLOCKCHAIN_ROUTERSERVICE_H
