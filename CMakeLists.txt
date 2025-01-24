# CMake configuration for SinesBox library

cmake_minimum_required(VERSION 3.10)
project(SinesBox VERSION 1.0.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the library sources
set(SINESBOX_SOURCES
    src/SinesBox.cpp
)

set(SINESBOX_HEADERS
    include/SinesBox.h
    include/SinesGlobalSettings.h
)

# Create the library
add_library(SinesBox STATIC ${SINESBOX_SOURCES} ${SINESBOX_HEADERS})

# Set the include directory for this target
target_include_directories(SinesBox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Installation configuration
install(TARGETS SinesBox
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(FILES ${SINESBOX_HEADERS} DESTINATION include/SinesBox)
