add_subdirectory (examples)

include_directories(
        cpp
        ${STXXL_INCLUDE_DIRS}
)

set(EXECUTABLE_OUTPUT_PATH "build/main")
build_tool(main)
