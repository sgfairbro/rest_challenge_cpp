
#include <string>

namespace rest
{

class DataProcessor
{
public:
    DataProcessor() = default; 
    virtual ~DataProcessor() = default; 

    void processInputJSON( const std::string& json );

    std::string buildOutputJSON();

private:

};

}
