cmake_minimum_required(VERSION 3.5.0)
set(TARGET_NAME UxasUtilities)
project("${TARGET_NAME}")

add_library(${TARGET_NAME} STATIC 
    ${PROJECT_SOURCE_DIR}/Algebra.cpp
    ${PROJECT_SOURCE_DIR}/CallbackTimer.cpp
    ${PROJECT_SOURCE_DIR}/FileSystemUtilities.cpp
    ${PROJECT_SOURCE_DIR}/FlatEarth.cpp
    ${PROJECT_SOURCE_DIR}/Permute.cpp
    ${PROJECT_SOURCE_DIR}/RouteExtension.cpp
    ${PROJECT_SOURCE_DIR}/SensorSteering.cpp
    ${PROJECT_SOURCE_DIR}/TimeUtilities.cpp
    ${PROJECT_SOURCE_DIR}/UnitConversions.cpp
    ${PROJECT_SOURCE_DIR}/UxAS_ConfigurationManager.cpp
    ${PROJECT_SOURCE_DIR}/UxAS_ConsoleLogger.cpp
    ${PROJECT_SOURCE_DIR}/UxAS_DatabaseLogger.cpp
    ${PROJECT_SOURCE_DIR}/UxAS_DatabaseLoggerHelper.cpp
    ${PROJECT_SOURCE_DIR}/UxAS_FileLogger.cpp
    ${PROJECT_SOURCE_DIR}/UxAS_HeadLogDataDatabaseLogger.cpp
    ${PROJECT_SOURCE_DIR}/UxAS_LogManager.cpp
    ${PROJECT_SOURCE_DIR}/UxAS_SentinelSerialBuffer.cpp
    ${PROJECT_SOURCE_DIR}/UxAS_Time.cpp
    ${PROJECT_SOURCE_DIR}/UxAS_TimerManager.cpp
    ${PROJECT_SOURCE_DIR}/UxAS_ZeroMQ.cpp
)

# add_dependencies(${TARGET_NAME} AnodEnv)

# Set specific compiler flags
target_compile_options(${TARGET_NAME} PRIVATE
"-fPIC"
$<$<CONFIG:DEBUG>:-Og>
)

# Set optional compiler flags
if(ENABLE_WARNINGS)
target_compile_options(${TARGET_NAME} PRIVATE -Wall)
endif()
if(ENABLE_COVERAGE)
target_compile_options(${TARGET_NAME} PRIVATE 
    -fprofile-arcs 
    -ftest-coverage
)
target_compile_definitions(${TARGET_NAME} PRIVATE GCOV_MODE=1)
endif()

# Specify the C++ standard to use
set_target_properties(${TARGET_NAME} PROPERTIES
CXX_STANDARD 11
CXX_STANDARD_REQUIRED ON
CXX_EXTENSIONS OFF
)

message("Here's the include path = $ENV{CPLUS_INCLUDE_PATH}")

target_include_directories(${TARGET_NAME} PUBLIC
    ${AnodEnv_IncludePath}
    ${PROJECT_SOURCE_DIR}/
    ${PROJECT_SOURCE_DIR}/../Includes/    
    ${PROJECT_SOURCE_DIR}/../Plans/
)

