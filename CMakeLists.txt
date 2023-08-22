cmake_minimum_required(VERSION 3.15)
project(prthgcpp LANGUAGES CXX)


# ########################################################################
set(PRTHGCPP_MAJOR 0)
set(PRTHGCPP_MINOR 1)
set(PRTHGCPP_PATCH 3)
set(PRTHGCPP_DATES 20230823)

set(PRTHGCPP_VERSION "${PRTHGCPP_MAJOR}.${PRTHGCPP_MINOR}.${PRTHGCPP_PATCH}")
set(PRTHGCPP_FULL_VERSION "${PRTHGCPP_MAJOR}.${PRTHGCPP_MINOR}.${PRTHGCPP_PATCH}.${PRTHGCPP_DATES}")

message(STATUS "(MSG) - ${PROJECT_NAME}: compiler ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "(MSG) - ${PROJECT_NAME}: configuring ${PRTHGCPP_FULL_VERSION}")
# ########################################################################


# ########################################################################
if(CMAKE_TOOLCHAIN_FILE STREQUAL "")
    message(STATUS "(MSG) - ${PROJECT_NAME}: CMAKE_TOOLCHAIN_FILE is not supplied")
else()
    message(STATUS "(MSG) - ${PROJECT_NAME}: CMAKE_TOOLCHAIN_FILE is supplied as '${CMAKE_TOOLCHAIN_FILE}'")
endif()
# ########################################################################


# ########################################################################
find_package(jsoncpp CONFIG REQUIRED)
find_package(cryptopp CONFIG REQUIRED)
find_package(Drogon CONFIG REQUIRED)
find_package(mailio CONFIG REQUIRED)
# ########################################################################


# ########################################################################
include(CheckIncludeFileCXX)

check_include_file_cxx(coroutine HAS_COROUTINE)

if(HAS_COROUTINE)
    set(CMAKE_CXX_STANDARD 20)
    message(STATUS "(MSG) - ${PROJECT_NAME}: using c++20")
else ()
    set(CMAKE_CXX_STANDARD 17)
    message(STATUS "(MSG) - ${PROJECT_NAME}: using c++17")
endif (HAS_COROUTINE)

if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Profile")
    set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "(MSG) - ${PROJECT_NAME}: build type is ${CMAKE_BUILD_TYPE}")
# ########################################################################


# ########################################################################
set(PRTHGCPP_SOURCE_FILE
    src/prthgcpp/prthgcpp.cc

    src/prthgcpp/classes/Cryptography.cc
    src/prthgcpp/classes/Utility.cc
)
# ########################################################################


# ########################################################################
add_library(${PROJECT_NAME}
    ${PRTHGCPP_SOURCE_FILE}
)

if(BUILD_SHARED_LIBS)
    # TODO
endif(BUILD_SHARED_LIBS)
# ########################################################################


# ########################################################################
# start of core required package
target_link_libraries(${PROJECT_NAME} PRIVATE JsonCpp::JsonCpp)
message(STATUS "(MSG) - ${PROJECT_NAME}: jsoncpp package found ${jsoncpp_VERSION}")

target_link_libraries(${PROJECT_NAME} PRIVATE cryptopp::cryptopp)
message(STATUS "(MSG) - ${PROJECT_NAME}: cryptopp package found ${cryptopp_VERSION}")
# end of core required package

# start of optional package
if(Drogon_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
    message(STATUS "(MSG) - ${PROJECT_NAME}: drogon package found ${Drogon_VERSION}")
    set(CMAKE_PRTHGCPP_INC_DROGON true)
else(Drogon_FOUND)
    message(STATUS "(MSG) - ${PROJECT_NAME}: drogon package not found")
    set(CMAKE_PRTHGCPP_INC_DROGON false)
endif(Drogon_FOUND)

if(mailio_FOUND)
    target_link_libraries(${PROJECT_NAME}  PRIVATE mailio)
    message(STATUS "(MSG) - ${PROJECT_NAME}: mailio package found ${mailio_VERSION}")
    set(CMAKE_PRTHGCPP_INC_MAILIO true)
else(mailio_FOUND)
    message(STATUS "(MSG) - ${PROJECT_NAME}: mailio package not found")
    set(CMAKE_PRTHGCPP_INC_MAILIO false)
endif(mailio_FOUND)
# end of optional package
# ########################################################################


# ########################################################################
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # reserved
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # reserved
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    # reserved
else()
	message(FATAL_ERROR "(FER) - ${PROJECT_NAME}: not support for ${CMAKE_SYSTEM_NAME}")
endif()
# ########################################################################


# ########################################################################
include(GenerateExportHeader)

generate_export_header(${PROJECT_NAME} EXPORT_FILE_NAME ${PROJECT_SOURCE_DIR}/src/prthgcpp/prthgcpp_export.gen.h)

configure_file(
    ${PROJECT_SOURCE_DIR}/src/prthgcpp/prthgcpp_config.h.in
    ${PROJECT_SOURCE_DIR}/src/prthgcpp/prthgcpp_config.gen.h
)
# ########################################################################


# ########################################################################
aux_source_directory(src/prthgcpp PRTHGCPP_INC_SRC)
aux_source_directory(src/prthgcpp/classes PRTHGCPP_CLASSES_INC_SRC)
aux_source_directory(src/prthgcpp/enums PRTHGCPP_ENUMS_INC_SRC)
aux_source_directory(src/prthgcpp/interfaces PRTHGCPP_INTERFACES_INC_SRC)
aux_source_directory(src/prthgcpp/structs PRTHGCPP_STRUCTS_INC_SRC)
aux_source_directory(src/prthgcpp/types PRTHGCPP_TYPES_INC_SRC)
# ########################################################################


# ########################################################################
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/prthgcpp
        ${PRTHGCPP_CLASSES_INC_SRC}
        ${PRTHGCPP_ENUMS_INC_SRC}
        ${PRTHGCPP_INTERFACES_INC_SRC}
        ${PRTHGCPP_STRUCTS_INC_SRC}
        ${PRTHGCPP_TYPES_INC_SRC}
)
# ########################################################################


# ########################################################################
if(PRTHGCPP_INC_TEST)
    add_subdirectory(test/cryptography)
endif(PRTHGCPP_INC_TEST)
# ########################################################################