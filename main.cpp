#include <pistache/endpoint.h>
#include <pistache/router.h>
#include "API/Service/RouterService.h"
#include "API/RESTController/StatusController.h"
#include "Blockchain/Blockchain.h"

using namespace Pistache;
using namespace std;
using namespace bc;

/*
struct HelloHandler : public Http::Handler {
HTTP_PROTOTYPE(HelloHandler)
    void onRequest(const Http::Request&, Http::ResponseWriter writer) override{
        writer.send(Http::Code::Ok, "Hello, World!");
    }
};
*/

auto setupRouter(){
    RouterService routerService;
    StatusController status;

    routerService.addController(status);

    return routerService.getHandler();
}

int main() {
    Blockchain blockchain;
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(8080));
    Http::Endpoint server(addr);

    server.init(Pistache::Http::Endpoint::options().threads(1));
    server.setHandler(setupRouter());

    cout << "Server started on http://" + addr.host() + ":" + addr.port().toString() << endl;
    server.serve();
}