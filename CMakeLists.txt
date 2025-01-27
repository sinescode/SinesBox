cmake_minimum_required(VERSION 3.10)
project(SinesBox VERSION 1.0.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the library sources and headers
set(SINESBOX_SOURCES
    src/SinesBox.cpp
)

set(SINESBOX_HEADERS
    include/SinesBox.h
    include/SinesGlobalSettings.h
)

# Create the library
add_library(SinesBox STATIC ${SINESBOX_SOURCES})

# Set the include directory for this target
target_include_directories(SinesBox
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
           $<INSTALL_INTERFACE:include>
)

# Installation configuration
install(TARGETS SinesBox
    EXPORT SinesBoxTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# Install headers
install(FILES ${SINESBOX_HEADERS} DESTINATION include/SinesBox)

# Export the library for use by other projects
install(EXPORT SinesBoxTargets
    FILE SinesBoxConfig.cmake
    NAMESPACE SinesBox::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SinesBox
)

# Generate a package version file for CMake
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/SinesBoxConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Install the package version file
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/SinesBoxConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SinesBox
)
