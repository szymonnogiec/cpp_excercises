#include <gtest/gtest.h>

class TestingTest : public testing::Test
{
public:

};

TEST_F(TestingTest, FirstTest)
{
    EXPECT_NE(1, 2);
}