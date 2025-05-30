package(default_visibility = ["//visibility:public"])

cc_library(
    name = "security_issues",
    srcs = ["security_issues.cc"],
    hdrs = ["security_issues.h"],
)

cc_binary(
    name = "security_issues_test",
    srcs = ["security_issues_test.cc"],
    deps = [
        ":security_issues",
    ],
)

cc_binary(
    name = "vulnerable_demo",
    srcs = ["vulnerable_demo.cc"],
    deps = [
        ":security_issues",
    ],
) 
