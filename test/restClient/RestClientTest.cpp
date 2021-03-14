
#include "RestClient.h"
#include "RestServer.h"

#include "gtest/gtest.h"

#include <memory>
#include <thread>

using namespace Pistache; 
using namespace std; 

TEST( RestClientTest, TestClientCallAPI )
{
  string response("response");
  Address addr(  "https://covid-19-data.p.rapidapi.com/totals" );
  auto opts = Http::Endpoint::options().threads(1);

  rest::RestClient client( "https://covid-19-data.p.rapidapi.com/totals");
  auto data = client.getDataFromServer();
  EXPECT_EQ( response, data );

  client.shutdown();
}


TEST( RestClientTest, TestClientServerCommunication )
{
  string response("response");
  Address addr( "localhost", Port(9080));
  auto opts = Http::Endpoint::options().threads(1);
  Http::Endpoint server( addr );
  server.init( opts );
  server.setHandler( Http::make_handler<rest::RestServer >( response) );
  server.serveThreaded();

  const string server_address( "localhost:" + server.getPort().toString() );

  rest::RestClient client( server_address );
  auto data = client.getDataFromServer();
  EXPECT_EQ( response, data );

  client.shutdown();
  server.shutdown();
}
