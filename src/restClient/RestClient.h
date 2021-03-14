#include "pistache/client.h"

#include <string>

namespace rest
{

class RestClient
{
public:
    RestClient(
    		std::string serverAddress,
			int clientWaitTimeSeconds = 5 );
    virtual ~RestClient() = default; 

    /*
     * @brief attempts to get data from server configured with
     * server address
     * @return string containing data received from server
     * @remark expected that string data is JSON
     */
    std::string getDataFromServer();

    /*
     * @brief shuts down mClient
     */
    void shutdown();

private:

    void initializeClient();

    Pistache::Http::Client mClient;

    std::string mServerAddress;
    int mClientWaitTimeSeconds;

};

}
