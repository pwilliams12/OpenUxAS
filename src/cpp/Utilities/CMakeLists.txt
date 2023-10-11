cmake_minimum_required(VERSION 3.5.0)
set(TARGET_NAME UxasUtilities)
project("${TARGET_NAME}")

add_library(${TARGET_NAME} STATIC 
    ${PROJECT_SOURCE_DIR}/src/Algebra.cpp
    ${PROJECT_SOURCE_DIR}/src/CallbackTimer.cpp
    ${PROJECT_SOURCE_DIR}/src/FileSystemUtilities.cpp
    ${PROJECT_SOURCE_DIR}/src/FlatEarth.cpp
    ${PROJECT_SOURCE_DIR}/src/Permute.cpp
    ${PROJECT_SOURCE_DIR}/src/RouteExtension.cpp
    ${PROJECT_SOURCE_DIR}/src/SensorSteering.cpp
    ${PROJECT_SOURCE_DIR}/src/TimeUtilities.cpp
    ${PROJECT_SOURCE_DIR}/src/UnitConversions.cpp
    ${PROJECT_SOURCE_DIR}/src/UxAS_ConfigurationManager.cpp
    ${PROJECT_SOURCE_DIR}/src/UxAS_ConsoleLogger.cpp
    ${PROJECT_SOURCE_DIR}/src/UxAS_DatabaseLogger.cpp
    ${PROJECT_SOURCE_DIR}/src/UxAS_DatabaseLoggerHelper.cpp
    ${PROJECT_SOURCE_DIR}/src/UxAS_FileLogger.cpp
    ${PROJECT_SOURCE_DIR}/src/UxAS_HeadLogDataDatabaseLogger.cpp
    ${PROJECT_SOURCE_DIR}/src/UxAS_LogManager.cpp
    ${PROJECT_SOURCE_DIR}/src/UxAS_SentinelSerialBuffer.cpp
    ${PROJECT_SOURCE_DIR}/src/UxAS_Time.cpp
    ${PROJECT_SOURCE_DIR}/src/UxAS_TimerManager.cpp
    ${PROJECT_SOURCE_DIR}/src/UxAS_ZeroMQ.cpp
)

# Specify the C++ standard to use
set_target_properties(${TARGET_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_include_directories(${TARGET_NAME} PUBLIC
    ${AnodEnv_IncludePath}
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/../Includes/    
    "$<TARGET_PROPERTY:UxasPlans,INTERFACE_INCLUDE_DIRECTORIES>"
)

if (${UNIT_TEST})
    add_executable("TimeTest" ${PROJECT_SOURCE_DIR}/unitTests/UxAS_Time_Test.cpp)
    target_include_directories("TimeTest" PUBLIC ${PROJECT_SOURCE_DIR}/unitTests/)
    target_link_directories("TimeTest" PUBLIC ${AnodEnv_LibPath})
    target_link_libraries("TimeTest" PUBLIC ${TARGET_NAME} gtest gtest_main)
    set_target_properties("TimeTest" PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
    )
endif()