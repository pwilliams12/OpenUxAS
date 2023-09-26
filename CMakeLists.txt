cmake_minimum_required(VERSION 3.5.0)
set(TARGET_NAME uxas)
project("${TARGET_NAME}")
include(GNUInstallDirs)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/cpp)

# Add ANOD dev environment
message("Creating anod dependency")
execute_process(COMMAND ./anod printenv uxas --build-env --lib-path
    OUTPUT_VARIABLE AnodEnv_LibPath
    WORKING_DIRECTORY "./"
    ECHO_OUTPUT_VARIABLE ${AnodEnv_LibPath}
)
execute_process(COMMAND ./anod printenv uxas --build-env --cplus-include-path
    OUTPUT_VARIABLE AnodEnv_IncludePath
    WORKING_DIRECTORY "./"
    ECHO_OUTPUT_VARIABLE ${AnodEnv_IncludePath}
)

# Set specific compiler flags
add_compile_options(
    "-fPIC"
    $<$<CONFIG:Release>:"-O3">
    $<$<CONFIG:Debug>:"-Og -g">    
    $<$<BOOL:${ENABLE_WARNINGS}>:"-Wall">
    $<$<BOOL:${ENABLE_COVERAGE}>:"-fprofile-arcs -ftest-coverage">
)

add_compile_definitions(
    "BOOST_GEOMETRY_DISABLE_DEPRECATED_03_WARNING=1"
    $<$<BOOL:${ENABLE_COVERAGE}>:"GCOV_MODE=1">
)

# Set optional compiler flags

add_subdirectory(${PROJECT_SOURCE_DIR}/src/cpp/Communications)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/cpp/DPSS)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/cpp/Plans)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/cpp/Services)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/cpp/Tasks)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/cpp/Utilities)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/cpp/VisilibityLib)

# Create binary
add_executable(${TARGET_NAME} ${SOURCE_DIR}/UxAS_Main.cpp)

# Specify the C++ standard to use
set_target_properties(${TARGET_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_link_options(${TARGET_NAME} PUBLIC
    -static-libgcc
    -static-libstdc++
)

target_include_directories(${TARGET_NAME} PUBLIC
    ${AnodEnv_LibPath}
    ${SOURCE_DIR}/Includes/
    ${SOURCE_DIR}/Tasks/
    ${SOURCE_DIR}/VisilibityLib/
    ${PROJECT_SOURCE_DIR}/resources/AutomationDiagramDataService # TODO: Review need for this.
)
target_link_directories(${TARGET_NAME} PUBLIC
    ${AnodEnv_LibPath}
    $ENV{LIBRARY_PATH}
)
# Order of linked libraries matters since they're static
target_link_libraries(${TARGET_NAME} 
    UxasCommunications
    UxasServices
    UxasVisilibityLib
    UxasPlans
    UxasTasks
    UxasDPSS
    UxasUtilities
    lmcp 
    zyre 
    pugixml 
    SQLiteCpp 
    sqlite3 
    czmq 
    serial 
    libzmq.a
    boost_filesystem 
    boost_regex 
    uuid
)

# Create install target
install(TARGETS ${TARGET_NAME})
