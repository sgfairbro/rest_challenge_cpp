
#include "DataProcessor.h"

namespace rest
{

class Controller
{
public:
    Controller() = default; 
    virtual ~Controller() = default; 

private:

   rest::DataProcessor mProcessor;

};

}
