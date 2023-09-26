cmake_minimum_required(VERSION 3.5.0)
set(TARGET_NAME UxasServices)
project("${TARGET_NAME}")

add_library(${TARGET_NAME} STATIC 
    ${PROJECT_SOURCE_DIR}/src/00_ServiceTemplate.cpp
    ${PROJECT_SOURCE_DIR}/src/01_HelloWorld.cpp
    ${PROJECT_SOURCE_DIR}/src/AssignmentTreeBranchBoundBase.cpp
    ${PROJECT_SOURCE_DIR}/src/AssignmentTreeBranchBoundService.cpp
    ${PROJECT_SOURCE_DIR}/src/AutomationDiagramDataService.cpp
    ${PROJECT_SOURCE_DIR}/src/AutomationRequestValidatorService.cpp
    ${PROJECT_SOURCE_DIR}/src/BatchSummaryService.cpp
    ${PROJECT_SOURCE_DIR}/src/LoiterLeash.cpp
    ${PROJECT_SOURCE_DIR}/src/MessageLoggerDataService.cpp
    ${PROJECT_SOURCE_DIR}/src/OperatingRegionStateService.cpp
    ${PROJECT_SOURCE_DIR}/src/OsmPlannerService.cpp
    ${PROJECT_SOURCE_DIR}/src/PlanBuilderService.cpp
    ${PROJECT_SOURCE_DIR}/src/RouteAggregatorService.cpp
    ${PROJECT_SOURCE_DIR}/src/RoutePlannerService.cpp
    ${PROJECT_SOURCE_DIR}/src/RoutePlannerVisibilityService.cpp
    ${PROJECT_SOURCE_DIR}/src/SendMessagesService.cpp
    ${PROJECT_SOURCE_DIR}/src/SensorManagerService.cpp
    ${PROJECT_SOURCE_DIR}/src/SerialAutomationRequestTestService.cpp
    ${PROJECT_SOURCE_DIR}/src/ServiceBase.cpp
    ${PROJECT_SOURCE_DIR}/src/ServiceManager.cpp
    ${PROJECT_SOURCE_DIR}/src/SimpleWaypointPlanManagerService.cpp
    ${PROJECT_SOURCE_DIR}/src/StatusReportService.cpp
    ${PROJECT_SOURCE_DIR}/src/SteeringService.cpp
    ${PROJECT_SOURCE_DIR}/src/Test_SimulationTime.cpp
    ${PROJECT_SOURCE_DIR}/src/WaypointPlanManagerService.cpp
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
    ${PROJECT_SOURCE_DIR}/../../../resources/AutomationDiagramDataService/
    "$<TARGET_PROPERTY:UxasCommunications,INTERFACE_INCLUDE_DIRECTORIES>"
    "$<TARGET_PROPERTY:UxasDPSS,INTERFACE_INCLUDE_DIRECTORIES>"
    "$<TARGET_PROPERTY:UxasTasks,INTERFACE_INCLUDE_DIRECTORIES>"
)