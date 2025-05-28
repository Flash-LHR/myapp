#include "app/world/world.h"

#include <gtest/gtest.h>

namespace {

TEST(WorldTest, ReturnsWorld) { EXPECT_EQ("World", world()); }

}  // namespace
