cmake_minimum_required(VERSION 3.5.0)
set(TARGET_NAME uxas)
project("${TARGET_NAME}")
include(GNUInstallDirs)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/cpp)
set(SRC_FILES
    ${SOURCE_DIR}/VisilibityLib/visilibity.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/Proxy/ThreadRunnerBase.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/Proxy/ZmqProxy.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/Receivers/MsgReceiverSentinel
    ${SOURCE_DIR}/Communications/ZeroMq/Receivers/SetArrayClientList.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/Receivers/ZmqGenericReceiver.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/Receivers/ZmqTcpReceiver.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/Senders/MsgSenderSentinel.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/Senders/ZmqTcpSender.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/Sockets/ZmqSocketBase.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/Sockets/ZmqSocketInitializer.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/Sockets/ZmqTcpSocket.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/ZmqAttributedMsgSenderReceiver.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/ZmqPullReceiver.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/ZmqPushSender.cpp
    ${SOURCE_DIR}/Communications/ZeroMq/ZmqTcpSenderReceiver.cpp
    ${SOURCE_DIR}/Communications/AddressedAttributedMessage.cpp
    ${SOURCE_DIR}/Communications/ImpactSubscribePushBridge.cpp
    ${SOURCE_DIR}/Communications/LmcpObjectMessageReceiverPipe.cpp
    ${SOURCE_DIR}/Communications/LmcpObjectMessageSenderPipe.cpp
    ${SOURCE_DIR}/Communications/LmcpObjectMessageTcpReceiverSenderPipe.cpp
    ${SOURCE_DIR}/Communications/LmcpObjectNetworkBridgeManager.cpp
    ${SOURCE_DIR}/Communications/LmcpObjectNetworkClientBase.cpp
    ${SOURCE_DIR}/Communications/LmcpObjectNetworkPublishPullBridge.cpp
    ${SOURCE_DIR}/Communications/LmcpObjectNetworkSerialBridge.cpp
    ${SOURCE_DIR}/Communications/LmcpObjectNetworkServer.cpp
    ${SOURCE_DIR}/Communications/LmcpObjectNetworkSubscribePushBridge.cpp
    ${SOURCE_DIR}/Communications/LmcpObjectNetworkTcpBridge.cpp
    ${SOURCE_DIR}/Communications/LmcpObjectNetworkZeroMqZyreBridge.cpp
    ${SOURCE_DIR}/Communications/TransportReceiverBase.cpp
    ${SOURCE_DIR}/Communications/ZeroMqAddressedAttributedMessageReceiver.cpp
    ${SOURCE_DIR}/Communications/ZeroMqAddressedAttributedMessageSender.cpp
    ${SOURCE_DIR}/Communications/ZeroMqAddressedAttributedMessageTcpReceiverSender.cpp
    ${SOURCE_DIR}/Communications/ZeroMqAddressStringReceiver.cpp
    ${SOURCE_DIR}/Communications/ZeroMqAddressStringSender.cpp
    ${SOURCE_DIR}/Communications/ZeroMqFabric.cpp
    ${SOURCE_DIR}/Communications/ZeroMqReceiverBase.cpp
    ${SOURCE_DIR}/Communications/ZeroMqSenderBase.cpp
    ${SOURCE_DIR}/Communications/ZeroMqZyreBridge.cpp
    ${SOURCE_DIR}/DPSS/CoordinateConversions.cpp
    ${SOURCE_DIR}/DPSS/Dpss.cpp
    ${SOURCE_DIR}/DPSS/DpssApi.cpp
    ${SOURCE_DIR}/DPSS/DpssDataTypes.cpp
    ${SOURCE_DIR}/DPSS/DpssUtilities.cpp
    ${SOURCE_DIR}/DPSS/DRand.cpp
    ${SOURCE_DIR}/DPSS/PlanOffset.cpp
    ${SOURCE_DIR}/DPSS/PlanPrecisely.cpp
    ${SOURCE_DIR}/DPSS/PlanQuickly.cpp
    ${SOURCE_DIR}/DPSS/SegmentMap.cpp
    ${SOURCE_DIR}/DPSS/SensorSteering2.cpp
    ${SOURCE_DIR}/Plans/CGrid.cpp
    ${SOURCE_DIR}/Plans/Edge.cpp
    ${SOURCE_DIR}/Plans/Polygon.cpp
    ${SOURCE_DIR}/Plans/Position.cpp
    ${SOURCE_DIR}/Plans/Trajectory.cpp
    ${SOURCE_DIR}/Plans/VisibilityGraph.cpp
    ${SOURCE_DIR}/Plans/Waypoint.cpp
    ${SOURCE_DIR}/Services/00_ServiceTemplate.cpp
    ${SOURCE_DIR}/Services/01_HelloWorld.cpp
    ${SOURCE_DIR}/Services/AssignmentTreeBranchBoundBase.cpp
    ${SOURCE_DIR}/Services/AssignmentTreeBranchBoundService.cpp
    ${SOURCE_DIR}/Services/AutomationDiagramDataService.cpp
    ${SOURCE_DIR}/Services/AutomationRequestValidatorService.cpp
    ${SOURCE_DIR}/Services/BatchSummaryService.cpp
    ${SOURCE_DIR}/Services/LoiterLeash.cpp
    ${SOURCE_DIR}/Services/MessageLoggerDataService.cpp
    ${SOURCE_DIR}/Services/OperatingRegionStateService.cpp
    ${SOURCE_DIR}/Services/OsmPlannerService.cpp
    ${SOURCE_DIR}/Services/PlanBuilderService.cpp
    ${SOURCE_DIR}/Services/RouteAggregatorService.cpp
    ${SOURCE_DIR}/Services/RoutePlannerService.cpp
    ${SOURCE_DIR}/Services/RoutePlannerVisibilityService.cpp
    ${SOURCE_DIR}/Services/SendMessagesService.cpp
    ${SOURCE_DIR}/Services/SensorManagerService.cpp
    ${SOURCE_DIR}/Services/SerialAutomationRequestTestService.cpp
    ${SOURCE_DIR}/Services/ServiceBase.cpp
    ${SOURCE_DIR}/Services/ServiceManager.cpp
    ${SOURCE_DIR}/Services/SimpleWaypointPlanManagerService.cpp
    ${SOURCE_DIR}/Services/StatusReportService.cpp
    ${SOURCE_DIR}/Services/SteeringService.cpp
    ${SOURCE_DIR}/Services/Test_SimulationTime.cpp
    ${SOURCE_DIR}/Services/WaypointPlanManagerService.cpp
    ${SOURCE_DIR}/Tasks/00_TaskTemplate.cpp
    ${SOURCE_DIR}/Tasks/AngledAreaSearchTaskService.cpp
    ${SOURCE_DIR}/Tasks/AssignmentCoordinatorTaskService.cpp
    ${SOURCE_DIR}/Tasks/BlockadeTaskService.cpp
    ${SOURCE_DIR}/Tasks/CmasiAreaSearchTaskService.cpp
    ${SOURCE_DIR}/Tasks/CmasiLineSearchTaskService.cpp
    ${SOURCE_DIR}/Tasks/CmasiPointSearchTaskService.cpp
    ${SOURCE_DIR}/Tasks/CommRelayTaskService.cpp
    ${SOURCE_DIR}/Tasks/CordonTaskService.cpp
    ${SOURCE_DIR}/Tasks/DynamicTaskServiceBase.cpp
    ${SOURCE_DIR}/Tasks/EscortTaskService.cpp
    ${SOURCE_DIR}/Tasks/ImpactLineSearchTaskService.cpp
    ${SOURCE_DIR}/Tasks/ImpactPointSearchTaskService.cpp
    ${SOURCE_DIR}/Tasks/LoiterTaskService.cpp
    ${SOURCE_DIR}/Tasks/MultiVehicleWatchTaskService.cpp
    ${SOURCE_DIR}/Tasks/MustFlyTaskService.cpp
    ${SOURCE_DIR}/Tasks/OverwatchTaskService.cpp
    ${SOURCE_DIR}/Tasks/PatternSearchTaskService.cpp
    ${SOURCE_DIR}/Tasks/RendezvousTask.cpp
    ${SOURCE_DIR}/Tasks/TaskManagerService.cpp
    ${SOURCE_DIR}/Tasks/TaskServiceBase.cpp
    ${SOURCE_DIR}/Tasks/TaskTrackerService.cpp
)

# Add ANOD dev environment
message("Creating anod dependency")
message("${SRC_FILES}")
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
# # message("Here's the output = ${AnodEnvFileVar}")
# # execute_process(COMMAND ${AnodEnvFileVar}
# execute_process(COMMAND source "AnodEnvFile.out"
#     COMMAND env
#     WORKING_DIRECTORY "./"
#     COMMAND_ECHO STDOUT
# )


# Create intermediate file as CMake messes up 
if(DEFINED SKIP_ANOD_SETUP)
    message("Skipping anod setup")
else()
    # message("Creating anod dependency")
    # execute_process(COMMAND NO_INSTALL_VENV=1 ./anod printenv uxas --build-env
    #     OUTPUT_VARIABLE AnodEnvFileVar
    #     WORKING_DIRECTORY "./"
    #     COMMAND_ECHO STDOUT
    # )
    # message("Here's the output = ${AnodEnvFileVar}")
    # execute_process(COMMAND eval "${AnodEnvFileVar}"
    #     WORKING_DIRECTORY "./"
    #     COMMAND_ECHO STDOUT
    # )
    # add_custom_command(OUTPUT AnodEnvFile.out
    #     COMMAND NO_INSTALL_VENV=1 ./anod printenv uxas --build-env > AnodEnvFile.out
    #     WORKING_DIRECTORY "../")
    # add_custom_target(AnodEnv ALL 
    #     COMMAND eval "$(cat AnodEnvFile.out)"
    #     WORKING_DIRECTORY "../"
    #     DEPENDS AnodEnvFile.out)
endif()

# Define common functionality to all libraries
function(commonSetup TARGET_NAME)
    # Setup anod environment if not already setup
    if (NOT SKIP_ANOD_SETUP)
        message("Adding AnodEnv dependency within FUNCTION***")
        # add_dependencies(${TARGET_NAME} AnodEnv)
    else()
        message("Not expected to be here... ${SKIP_ANOD_SETUP}")
    endif()

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
endfunction()

add_subdirectory(${PROJECT_SOURCE_DIR}/src/cpp/Utilities)

# Create binary
add_executable(${TARGET_NAME} ${SOURCE_DIR}/UxAS_Main.cpp ${SRC_FILES})
# if(SKIP_ANOD_SETUP)
#     message(DEBUG "Skipping anod setup")
# else()
#     add_dependencies(${TARGET_NAME} AnodEnv)
# endif()

# Set specific compiler flags
target_compile_options(${TARGET_NAME} PUBLIC
    "-fPIC"
    $<$<CONFIG:DEBUG>:-Og>
)
if(ENABLE_WARNINGS)
    target_compile_options(${TARGET_NAME} PUBLIC -Wall)
endif()
if(ENABLE_COVERAGE)
    target_compile_options(${TARGET_NAME} PUBLIC -fprofile-arcs -ftest-coverage)
    target_compile_definitions(${TARGET_NAME} PUBLIC GCOV_MODE=1)
endif()

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
    ${SOURCE_DIR}/Communications/ZeroMq/Proxy
    ${SOURCE_DIR}/Communications/ZeroMq/Receivers
    ${SOURCE_DIR}/Communications/ZeroMq/Senders
    ${SOURCE_DIR}/Communications/ZeroMq/Sockets
    ${SOURCE_DIR}/Communications/ZeroMq
    ${SOURCE_DIR}/Communications/
    ${SOURCE_DIR}/DPSS/
    ${SOURCE_DIR}/Includes/
    ${SOURCE_DIR}/Plans/
    ${SOURCE_DIR}/Services/
    ${SOURCE_DIR}/Tasks/
    ${SOURCE_DIR}/Utilities/
    ${SOURCE_DIR}/VisilibityLib/
    ${PROJECT_SOURCE_DIR}/resources/AutomationDiagramDataService # TODO: Review need for this.
)
target_link_directories(${TARGET_NAME} PUBLIC
    ${AnodEnv_LibPath}
    $ENV{LIBRARY_PATH}
)
target_link_libraries(${TARGET_NAME} 
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
