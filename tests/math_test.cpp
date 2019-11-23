#include <gtest/gtest.h>

#include "math_tasks.h"

class MathTest : public testing::Test
{
 public:

};

TEST_F(MathTest, CalculatesSumCorrectly)
{
  EXPECT_EQ(math::sum_of_divisible_by_three_and_five(16),60 );
}

TEST_F(MathTest, CalculatesGDCCorrectly)
{
  EXPECT_EQ(math::greatest_common_divisor(2, 1),1 );
  EXPECT_EQ(math::greatest_common_divisor(16, 4),4 );
  EXPECT_EQ(math::greatest_common_divisor(1535460, 153000),60 );
  EXPECT_EQ(math::greatest_common_divisor(137, 137),137 );

}

