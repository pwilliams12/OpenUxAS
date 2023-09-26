cmake_minimum_required(VERSION 3.5.0)
set(TARGET_NAME UxasCommunications)
project("${TARGET_NAME}")

add_library(${TARGET_NAME} STATIC 
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Proxy/ThreadRunnerBase.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Proxy/ZmqProxy.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Receivers/MsgReceiverSentinel
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Receivers/SetArrayClientList.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Receivers/ZmqGenericReceiver.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Receivers/ZmqTcpReceiver.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Senders/MsgSenderSentinel.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Senders/ZmqTcpSender.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Sockets/ZmqSocketBase.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Sockets/ZmqSocketInitializer.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Sockets/ZmqTcpSocket.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/ZmqAttributedMsgSenderReceiver.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/ZmqPullReceiver.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/ZmqPushSender.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/ZmqTcpSenderReceiver.cpp
    ${PROJECT_SOURCE_DIR}/src/AddressedAttributedMessage.cpp
    ${PROJECT_SOURCE_DIR}/src/ImpactSubscribePushBridge.cpp
    ${PROJECT_SOURCE_DIR}/src/LmcpObjectMessageReceiverPipe.cpp
    ${PROJECT_SOURCE_DIR}/src/LmcpObjectMessageSenderPipe.cpp
    ${PROJECT_SOURCE_DIR}/src/LmcpObjectMessageTcpReceiverSenderPipe.cpp
    ${PROJECT_SOURCE_DIR}/src/LmcpObjectNetworkBridgeManager.cpp
    ${PROJECT_SOURCE_DIR}/src/LmcpObjectNetworkClientBase.cpp
    ${PROJECT_SOURCE_DIR}/src/LmcpObjectNetworkPublishPullBridge.cpp
    ${PROJECT_SOURCE_DIR}/src/LmcpObjectNetworkSerialBridge.cpp
    ${PROJECT_SOURCE_DIR}/src/LmcpObjectNetworkServer.cpp
    ${PROJECT_SOURCE_DIR}/src/LmcpObjectNetworkSubscribePushBridge.cpp
    ${PROJECT_SOURCE_DIR}/src/LmcpObjectNetworkTcpBridge.cpp
    ${PROJECT_SOURCE_DIR}/src/LmcpObjectNetworkZeroMqZyreBridge.cpp
    ${PROJECT_SOURCE_DIR}/src/TransportReceiverBase.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMqAddressedAttributedMessageReceiver.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMqAddressedAttributedMessageSender.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMqAddressedAttributedMessageTcpReceiverSender.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMqAddressStringReceiver.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMqAddressStringSender.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMqFabric.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMqReceiverBase.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMqSenderBase.cpp
    ${PROJECT_SOURCE_DIR}/src/ZeroMqZyreBridge.cpp
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
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Proxy/
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Receivers/
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Senders/
    ${PROJECT_SOURCE_DIR}/src/ZeroMq/Sockets/
    "$<TARGET_PROPERTY:UxasUtilities,INTERFACE_INCLUDE_DIRECTORIES>"
    "$<TARGET_PROPERTY:UxasServices,INTERFACE_INCLUDE_DIRECTORIES>"
)