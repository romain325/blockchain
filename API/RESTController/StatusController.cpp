//
// Created by romain on 11/04/2021.
//

#include "StatusController.h"

using namespace Pistache::Rest;

void StatusController::setupRoutes(Rest::Router *router) {
    Pistache::Rest::Routes::Get(*router, this->m_requestMapping + "/hello", Routes::bind(&StatusController::helloworld, this));
}

void StatusController::helloworld(const Request &req, Http::ResponseWriter rep) {
    rep.send(Http::Code::Ok, "Hello World!");
}
