#include "app/hello/hello.h"

#include <gtest/gtest.h>

namespace {

TEST(HelloTest, ReturnsHello) { EXPECT_EQ("Hello", hello()); }

}  // namespace
