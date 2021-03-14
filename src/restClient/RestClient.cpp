#include "RestClient.h"

using namespace Pistache;
using std::string;

namespace rest
{
RestClient::RestClient(
		std::string serverAddress,
		int clientWaitTimeSeconds ) :
		mServerAddress( serverAddress ),
		mClientWaitTimeSeconds( clientWaitTimeSeconds )
{
	initializeClient();
}

string RestClient::getDataFromServer()
{
	string data;
	auto rb = mClient.get( mServerAddress );
	auto response =
		  rb.header<Http::Header::Connection>(Http::ConnectionControl::KeepAlive)
			  .send();
	bool done = false;
	response.then(
	  [&done, &data](Http::Response rsp) {
		if (rsp.code() == Http::Code::Ok)
		{
			done = true;
			data = rsp.body();
		}
		else
		{
			std::cout << "RestClient::getDataFromServer: bad code: " <<  rsp.code() << std::endl;
		}

	  },
	  Async::IgnoreException);

  Async::Barrier<Http::Response> barrier(response);
  barrier.wait_for(std::chrono::seconds( mClientWaitTimeSeconds ));

  return data;
}

void RestClient::shutdown()
{
	mClient.shutdown();
}

void RestClient::initializeClient()
{
	mClient.init();
}

}
