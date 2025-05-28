package(default_visibility = ["//visibility:public"])

cc_library(
    name = "world",
    srcs = ["world.cc"],
    hdrs = ["world.h"],
)

cc_test(
    name = "world_test",
    srcs = ["world_test.cc"],
    deps = [
        ":world",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
