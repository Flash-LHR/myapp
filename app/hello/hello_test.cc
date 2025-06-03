#include "app/hello/hello.h"

#include <gtest/gtest.h>

namespace {

TEST(HelloTest, ReturnsHello) {
  EXPECT_EQ("Hello", hello(2));
  EXPECT_EQ("Hell1o", hello(0));
}

}  // namespace
