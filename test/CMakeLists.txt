
set(QML_IMPORT_PATH
    ${CMAKE_BINARY_DIR}/LazyTools
    CACHE STRING "" FORCE)

add_definitions(-DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB_RECURSE QML_FILES *.qml)
add_custom_target(qmltestfiles SOURCES ${QML_FILES})

enable_testing()
add_executable(tests
    test.cpp
)
add_test(NAME tests COMMAND tests)

target_link_libraries(tests PRIVATE Qt6::QuickTest Qt6::Qml LazyTools)

