#include "RestServer.h"

using namespace Pistache;

using std::string; 

namespace rest
{

RestServer::RestServer()
{
  mResponse = "Hello World\n"; 
}

RestServer::RestServer( const string& response ) :
  mResponse( response ) 
{
}

}
