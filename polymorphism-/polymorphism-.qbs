import qbs

CppApplication {
    consoleApplication: true
    files: [
        "ArraySequence.h",
        "DynamicArray.h",
        "LinkedList.h",
        "ListSequence.h",
        "Sequence.h",
        "main.cpp",
        "queue.h",
        "tests.hpp",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
