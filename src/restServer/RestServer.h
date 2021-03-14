
#include "pistache/endpoint.h"
#include <string>

namespace rest
{

class RestServer : public Pistache::Http::Handler
{
public:

    HTTP_PROTOTYPE(RestServer)

    RestServer();

    RestServer( const std::string& response );

    virtual ~RestServer() = default; 

    void onRequest(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response) 
    {
      response.send(Pistache::Http::Code::Ok, mResponse);
    }

private:

    std::string mResponse; 

};

}
