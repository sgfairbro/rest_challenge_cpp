
#include "DataProcessor.h"

#include "gtest/gtest.h"

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

#include <memory>
#include <vector>

using namespace rapidjson;
using namespace std; 


class DataProcessorTest : public testing::Test
{
public:
  void SetUp()
  {
    mpDataProcessor = make_shared< rest::DataProcessor >(); 
  }

  void TearDown()
  {

  }

  shared_ptr< rest::DataProcessor > mpDataProcessor; 
};

// Test for inputting JSON through DataProcessor. No conditions are actually
// checked here.
TEST_F( DataProcessorTest, TestJSONOps )
{
	Document d;
	d.SetObject();

	rapidjson::Document::AllocatorType& allocator = d.GetAllocator();

	Value version(kNumberType);
	version.SetDouble(2.5);
	d.AddMember("version", version, allocator );

	vector< string > dependencies( { "googletest", "rapidjson", "pistache" } );

	Value comps(kArrayType);
	for( int i = 0; i < 3; ++i )
	{
		auto num = i + 1;
		Value obj(kObjectType);

		Value name(kObjectType);
		string name_str( "component_" + to_string(num) );
		name.SetString(name_str.c_str(), static_cast<SizeType>(name_str.length()), allocator);
		obj.AddMember("name", name, allocator);

		Value dep_array(kArrayType);
		for( const auto& dep : dependencies )
		{
			Value dep_obj(kObjectType);

			Value dep_name(kObjectType);
			dep_name.SetString(dep.c_str(), static_cast<SizeType>(dep.length()), allocator);
			dep_obj.AddMember( "name", dep_name, allocator );

			dep_obj.AddMember("year", 2021, allocator );

			dep_array.PushBack( dep_obj, allocator );
		}

		obj.AddMember( "dependencies", dep_array, allocator );

		Value val( kObjectType );
		val.SetBool( true );
		obj.AddMember("online", val, allocator );

		val.SetInt(num);
		obj.AddMember("id", val, allocator );

		comps.PushBack( obj, allocator );
	}

	d.AddMember( "components", comps, allocator );

	Value time_obj( kObjectType );
	Value val( kObjectType );
	val.SetInt(100);
	time_obj.AddMember("seconds", val, allocator );
	val.SetInt(49);
	time_obj.AddMember("nanos", val, allocator );
	d.AddMember( "time", time_obj, allocator );

	StringBuffer buffer;
	Writer<rapidjson::StringBuffer> writer(buffer);
	d.Accept(writer);

	mpDataProcessor->processInputJSON( buffer.GetString() );

	auto& comps_ref = d["components"];
	StringBuffer buffer2;
	Writer<rapidjson::StringBuffer> writer2(buffer2);
	comps_ref.Accept(writer2);
	std::cout << "printing components:" << std::endl;
	std::cout << buffer2.GetString() << std::endl;
}
