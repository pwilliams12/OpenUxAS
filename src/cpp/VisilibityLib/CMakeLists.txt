cmake_minimum_required(VERSION 3.5.0)
set(TARGET_NAME UxasVisilibityLib)
project("${TARGET_NAME}")

add_library(${TARGET_NAME} STATIC 
    ${PROJECT_SOURCE_DIR}/src/visilibity.cpp
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
    # "$<TARGET_PROPERTY:UxasServices,INTERFACE_INCLUDE_DIRECTORIES>"
)

if (${UNIT_TEST})
    set(TEST_NAME "VisilibityTest")
    add_executable(${TEST_NAME} ${PROJECT_SOURCE_DIR}/unitTests/Visilibity_Test.cpp)
    target_include_directories(${TEST_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/unitTests/)
    target_link_directories(${TEST_NAME} PUBLIC ${AnodEnv_LibPath})
    target_link_libraries(${TEST_NAME} PUBLIC ${TARGET_NAME} gtest gtest_main)
    set_target_properties(${TEST_NAME} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)
endif()