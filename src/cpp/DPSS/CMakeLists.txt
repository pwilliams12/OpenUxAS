cmake_minimum_required(VERSION 3.5.0)
set(TARGET_NAME UxasDPSS)
project("${TARGET_NAME}")

add_library(${TARGET_NAME} STATIC 
    ${PROJECT_SOURCE_DIR}/src/CoordinateConversions.cpp
    ${PROJECT_SOURCE_DIR}/src/Dpss.cpp
    ${PROJECT_SOURCE_DIR}/src/DpssApi.cpp
    ${PROJECT_SOURCE_DIR}/src/DpssDataTypes.cpp
    ${PROJECT_SOURCE_DIR}/src/DpssUtilities.cpp
    ${PROJECT_SOURCE_DIR}/src/DRand.cpp
    ${PROJECT_SOURCE_DIR}/src/PlanOffset.cpp
    ${PROJECT_SOURCE_DIR}/src/PlanPrecisely.cpp
    ${PROJECT_SOURCE_DIR}/src/PlanQuickly.cpp
    ${PROJECT_SOURCE_DIR}/src/SegmentMap.cpp
    ${PROJECT_SOURCE_DIR}/src/SensorSteering2.cpp
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
    "$<TARGET_PROPERTY:UxasUtilities,INTERFACE_INCLUDE_DIRECTORIES>"
)