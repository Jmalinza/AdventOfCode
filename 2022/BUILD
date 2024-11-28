[cc_binary(
    name = "day" + str(i),
    srcs = [
        "day" + str(i) + ".cpp",
        "day" + str(i) + ".h",
    ],
    data = [
        ":inputs",
    ],
    deps = [
        "//utility/cpp",
    ],
) for i in range(1, 8)]
