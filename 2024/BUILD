load("@rules_go//go:def.bzl", "go_binary")

cc_binary(
    name = "day1",
    srcs = [
        "day1.cpp",
        "day1.h",
    ],
    data = [
        ":inputs",
    ],
    deps = [
        "//utility/cpp",
    ],
)

go_binary(
    name = "day2",
    srcs = ["day2.go"],
    data = [
        ":inputs",
    ],
    deps = ["//utility/go:utility"],
)

go_binary(
    name = "day3",
    srcs = ["day3.go"],
    data = [
        ":inputs",
    ],
    deps = ["//utility/go:utility"],
)
