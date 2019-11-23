#include <gtest/gtest.h>

#include "IPv4.h"

class LF_Test : public testing::Test {

};

TEST_F(LF_Test, ReturnesOneElementIfNoDelim) {
  const std::string test_string{"This is some string"};

  auto split_result = lf::split_str(test_string, '.');

  ASSERT_EQ(split_result.size(), 1);
  EXPECT_EQ(split_result[0], test_string);
}

TEST_F(LF_Test, SplitsWordsCorrectly) {
  const std::string test_string_coma{"This,is,my,split,string"};
  const std::string test_string_dotted{"This.is.my.split.string"};
  const std::vector<std::string> expected{"This", "is", "my", "split", "string"};

  EXPECT_EQ(lf::split_str(test_string_coma, ','), expected);
  EXPECT_EQ(lf::split_str(test_string_dotted, '.'), expected);
}

TEST_F(LF_Test, Ipv4ThrowsIfStringIsntValid) {
  const std::string invalid_1{"123 123123123123"};
  const std::string invalid_2{"abc.ads.sd.d"};
  const std::string invalid_3{"192.168.0.256"};

  EXPECT_THROW(lf::IPv4{invalid_1}, std::runtime_error);
  EXPECT_THROW(lf::IPv4{invalid_2}, std::runtime_error);
  EXPECT_THROW(lf::IPv4{invalid_3}, std::runtime_error);
}

TEST_F(LF_Test, ParsesIpv4Correctly) {
  const std::string valid_1{"192.168.0.1"};

  lf::IPv4 valid_object_1{valid_1};
  lf::IPv4 valid_object_2{std::array<uint8_t, 4>{192, 168, 0, 1}};

  EXPECT_EQ(valid_1, valid_object_1.to_string());
  EXPECT_EQ(valid_1, valid_object_2.to_string());
}


