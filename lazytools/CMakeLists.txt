
qt_add_library(LazyTools SHARED)
qt_add_qml_module(LazyTools
    URI LazyTools
    VERSION 1.0
    SOURCES
        lazytools.h lazytools.cpp
        debouncefunction.h debouncefunction.cpp
)

set_target_properties(LazyTools PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.lazytools
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(LazyTools
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(LazyTools
    PRIVATE Qt6::Quick)

target_include_directories(LazyTools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
