cmake_minimum_required(VERSION 3.15)
project(prthgcpp-test LANGUAGES CXX)


# ########################################################################
add_executable(${PROJECT_NAME}
    main_test.cc
)
# ########################################################################


# ########################################################################
target_link_libraries(${PROJECT_NAME} PRIVATE JsonCpp::JsonCpp)
target_link_libraries(${PROJECT_NAME} PRIVATE cryptopp::cryptopp)

target_link_libraries(${PROJECT_NAME} PRIVATE prthgcpp)
# ########################################################################