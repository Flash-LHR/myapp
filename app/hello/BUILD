package(default_visibility = ["//visibility:public"])

cc_library(
    name = "hello",
    srcs = ["hello.cc"],
    hdrs = ["hello.h"],
)

cc_test(
    name = "hello_test",
    srcs = ["hello_test.cc"],
    deps = [
        ":hello",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
