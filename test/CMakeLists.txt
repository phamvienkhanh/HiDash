
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


##--- ui test -----
add_executable(test_ui
    main.cpp
)
qt_add_qml_module(test_ui
    URI TestUi
    VERSION 1.0
    QML_FILES main.qml
)
target_link_libraries(test_ui PRIVATE Qt6::Quick LazyTools)

