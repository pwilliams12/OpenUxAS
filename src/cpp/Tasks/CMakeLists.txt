cmake_minimum_required(VERSION 3.5.0)
set(TARGET_NAME UxasTasks)
project("${TARGET_NAME}")

add_library(${TARGET_NAME} STATIC 
    ${PROJECT_SOURCE_DIR}/src/00_TaskTemplate.cpp
    ${PROJECT_SOURCE_DIR}/src/AngledAreaSearchTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/AssignmentCoordinatorTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/BlockadeTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/CmasiAreaSearchTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/CmasiLineSearchTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/CmasiPointSearchTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/CommRelayTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/CordonTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/DynamicTaskServiceBase.cpp
    ${PROJECT_SOURCE_DIR}/src/EscortTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/ImpactLineSearchTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/ImpactPointSearchTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/LoiterTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/MultiVehicleWatchTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/MustFlyTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/OverwatchTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/PatternSearchTaskService.cpp
    ${PROJECT_SOURCE_DIR}/src/RendezvousTask.cpp
    ${PROJECT_SOURCE_DIR}/src/TaskManagerService.cpp
    ${PROJECT_SOURCE_DIR}/src/TaskServiceBase.cpp
    ${PROJECT_SOURCE_DIR}/src/TaskTrackerService.cpp
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
    "$<TARGET_PROPERTY:UxasServices,INTERFACE_INCLUDE_DIRECTORIES>"
)

