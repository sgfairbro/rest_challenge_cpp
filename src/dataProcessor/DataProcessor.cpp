
#include "DataProcessor.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

#include <iostream>

using namespace rapidjson;
using std::string;

namespace rest
{

void DataProcessor::processInputJSON( const std::string& json )
{
	Document doc;
	doc.Parse( json.c_str() );

	StringBuffer sb;
	PrettyWriter<StringBuffer> writer(sb);
	doc.Accept(writer);
	std::cout << "input string: " << sb.GetString() << std::endl;
}

string DataProcessor::buildOutputJSON()
{
	return string();
}

}
