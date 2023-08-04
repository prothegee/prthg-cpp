cmake_minimum_required(VERSION 3.15)
project(test-cryptography LANGUAGES CXX)


# ########################################################################
add_executable(${PROJECT_NAME}
    main.cc
)
# ########################################################################


# ########################################################################
target_link_libraries(${PROJECT_NAME} PRIVATE JsonCpp::JsonCpp)
target_link_libraries(${PROJECT_NAME} PRIVATE cryptopp::cryptopp)

target_link_libraries(${PROJECT_NAME} PRIVATE prthgcpp)
# ########################################################################