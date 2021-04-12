//
// Created by romain on 11/04/2021.
//

#include "RouterService.h"

std::shared_ptr<Pistache::Rest::Private::RouterHandler> RouterService::getHandler() const {
    return this->m_router.handler();
}

void RouterService::addController(RestController &controller) {
    controller.setupRoutes(&m_router);
}
