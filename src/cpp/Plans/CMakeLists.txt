cmake_minimum_required(VERSION 3.5.0)
set(TARGET_NAME UxasPlans)
project("${TARGET_NAME}")

add_library(${TARGET_NAME} STATIC 
    ${PROJECT_SOURCE_DIR}/src/CGrid.cpp
    ${PROJECT_SOURCE_DIR}/src/Edge.cpp
    ${PROJECT_SOURCE_DIR}/src/Polygon.cpp
    ${PROJECT_SOURCE_DIR}/src/Position.cpp
    ${PROJECT_SOURCE_DIR}/src/Trajectory.cpp
    ${PROJECT_SOURCE_DIR}/src/VisibilityGraph.cpp
    ${PROJECT_SOURCE_DIR}/src/Waypoint.cpp
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
    "$<TARGET_PROPERTY:UxasVisilibityLib,INTERFACE_INCLUDE_DIRECTORIES>"
)