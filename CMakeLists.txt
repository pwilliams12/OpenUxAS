cmake_minimum_required(VERSION 3.5.0)
set(TARGET_NAME uxas)
project("${TARGET_NAME}")
include(GNUInstallDirs)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set specific compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og -g")

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
    ${SOURCE_DIR}/Utilities/Algebra.cpp
    ${SOURCE_DIR}/Utilities/CallbackTimer.cpp
    ${SOURCE_DIR}/Utilities/FileSystemUtilities.cpp
    ${SOURCE_DIR}/Utilities/FlatEarth.cpp
    ${SOURCE_DIR}/Utilities/Permute.cpp
    ${SOURCE_DIR}/Utilities/RouteExtension.cpp
    ${SOURCE_DIR}/Utilities/SensorSteering.cpp
    ${SOURCE_DIR}/Utilities/TimeUtilities.cpp
    ${SOURCE_DIR}/Utilities/UnitConversions.cpp
    ${SOURCE_DIR}/Utilities/UxAS_ConfigurationManager.cpp
    ${SOURCE_DIR}/Utilities/UxAS_ConsoleLogger.cpp
    ${SOURCE_DIR}/Utilities/UxAS_DatabaseLogger.cpp
    ${SOURCE_DIR}/Utilities/UxAS_DatabaseLoggerHelper.cpp
    ${SOURCE_DIR}/Utilities/UxAS_FileLogger.cpp
    ${SOURCE_DIR}/Utilities/UxAS_HeadLogDataDatabaseLogger.cpp
    ${SOURCE_DIR}/Utilities/UxAS_LogManager.cpp
    ${SOURCE_DIR}/Utilities/UxAS_SentinelSerialBuffer.cpp
    ${SOURCE_DIR}/Utilities/UxAS_Time.cpp
    ${SOURCE_DIR}/Utilities/UxAS_TimerManager.cpp
    ${SOURCE_DIR}/Utilities/UxAS_ZeroMQ.cpp
)

# Create binary
add_executable(${TARGET_NAME} ${SOURCE_DIR}/UxAS_Main.cpp ${SRC_FILES})

# TODO: Replace these manual directories with conan or something from anod
set(SBX_DIR ${PROJECT_SOURCE_DIR}/infrastructure/sbx/x86_64-linux)
set(LMCP_DIR ${SBX_DIR}/uxas-lmcp-cpp/install)
set(PUGIXML_DIR ${SBX_DIR}/pugixml/install )
set(ZEROMQ_DIR ${SBX_DIR}/zeromq/install)
set(CPPZMQ_DIR ${SBX_DIR}/cppzmq/install)
set(CZMQ_DIR ${SBX_DIR}/czmq/install)
set(ZYRE_DIR ${SBX_DIR}/zyre/install)
set(SQLITECPP_DIR ${SBX_DIR}/sqlitecpp/install)
set(SQLITE_DIR ${SBX_DIR}/sqlite/install)
set(SERIAL_DIR ${SBX_DIR}/serial/install)
set(BOOST_DIR ${SBX_DIR}/boost/install)

target_include_directories(${TARGET_NAME} PUBLIC
    ${LMCP_DIR}/include       # Could I push this to conan.io ?
    ${PUGIXML_DIR}/include    # Could conanize
    ${ZEROMQ_DIR}/include     # Could conanize
    ${CZMQ_DIR}/include       # Could conanize
    ${CPPZMQ_DIR}/include     # Could conanize
    ${SQLITECPP_DIR}/include  # Could conanize
    ${SQLITE_DIR}/include     # Could conanize
    ${SERIAL_DIR}/include     # Could conanize
    ${ZYRE_DIR}/include       # Could conanize
    ${BOOST_DIR}/include      # Could conanize
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
    ${PROJECT_SOURCE_DIR}/resources/AutomationDiagramDataService  # TODO: Review need for this cludge!
)
target_link_directories( ${TARGET_NAME} PUBLIC
    ${LMCP_DIR}/lib
    ${PUGIXML_DIR}/lib
    ${ZEROMQ_DIR}/lib
    ${CZMQ_DIR}/lib
    ${SQLITE_DIR}/lib
    ${SQLITECPP_DIR}/lib
    ${SERIAL_DIR}/lib
    ${ZYRE_DIR}/lib
    ${BOOST_DIR}/lib
    )
target_link_libraries(${TARGET_NAME} lmcp zyre pugixml SQLiteCpp sqlite3 czmq serial libzmq.a
    boost_filesystem boost_regex uuid)

# Create install target
install(TARGETS ${TARGET_NAME})
