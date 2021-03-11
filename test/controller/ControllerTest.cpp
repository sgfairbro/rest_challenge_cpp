
#include "Controller.h"

#include "gtest/gtest.h"

#include <memory>

using namespace std;

class ControllerTest : public testing::Test
{
public:
  void SetUp()
  {
    mpController = make_shared< rest::Controller >(); 
  }

  void TearDown()
  {

  }

  shared_ptr< rest::Controller > mpController; 
};

TEST_F( ControllerTest, TestController )
{
  EXPECT_TRUE(true); 
}
