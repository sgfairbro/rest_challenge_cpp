
#include "DataProcessor.h"

#include <memory>

namespace rest
{

class RestClient;

class Controller
{
public:
    Controller( const std::string& serverAddress );
    virtual ~Controller() = default; 

    /*
     * @brief uses mpClient to get data from server and
     * mProcessor to process input data
     * @return true if client gets data successfully
     */
    bool processDataFromServer();

private:

   rest::DataProcessor mProcessor;
   std::unique_ptr< RestClient > mpClient;

};

}
