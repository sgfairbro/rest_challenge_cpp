#include "Controller.h"
#include "RestClient.h"

using std::make_unique;

namespace rest
{

Controller::Controller( const std::string& serverAddress )
{
	mpClient = make_unique< RestClient >( serverAddress );
}

bool Controller::processDataFromServer()
{
	auto str_data = mpClient->getDataFromServer();

}

}
