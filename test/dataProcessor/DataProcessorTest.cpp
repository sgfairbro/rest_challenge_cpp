
#include "DataProcessor.h"

#include "gtest/gtest.h"

#include <memory>

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

TEST_F( DataProcessorTest, TestDataProcessor )
{
  EXPECT_TRUE(true); 
}
