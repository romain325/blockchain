#include <pistache/endpoint.h>
#include <pistache/router.h>
#include "API/Service/RouterService.h"
#include "API/RESTController/StatusController.h"
#include "Blockchain/Blockchain.h"
#include "API/RESTController/blockchain_api/ChainController.h"
#include "API/RESTController/blockchain_api/TransactionController.h"

using namespace Pistache;
using namespace std;
using namespace bc;

Blockchain blockchain;

auto setupRouter(){
    RouterService routerService;

    StatusController status;
    ChainController chainController;
    TransactionController transactionController;

    routerService.addController(status);
    routerService.addController(chainController);
    routerService.addController(transactionController);

    return routerService.getHandler();
}

int main() {

    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(8080));
    Http::Endpoint server(addr);

    server.init(Pistache::Http::Endpoint::options().threads(1));
    server.setHandler(setupRouter());

    cout << "Server started on http://" + addr.host() + ":" + addr.port().toString() << endl;
    server.serve();
}