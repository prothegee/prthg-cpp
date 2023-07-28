cmake_minimum_required(VERSION 3.15)
project(prthgcpp LANGUAGES CXX)


# ########################################################################
set(PRTHGCPP_MAJOR 0)
set(PRTHGCPP_MINOR 0)
set(PRTHGCPP_PATCH 1)
set(PRTHGCPP_DATES 20230728)

set(PRTHGCPP_VERSION "${PRTHGCPP_MAJOR}.${PRTHGCPP_MINOR}.${PRTHGCPP_PATCH}.${PRTHGCPP_DATES}")

message(STATUS "(MSG) - ${PROJECT_NAME}: compiler ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "(MSG) - ${PROJECT_NAME}: configuring v${PRTHGCPP_VERSION}")
# ########################################################################


# ########################################################################
if(INC_VPCKG)
    include("${INC_VPCKG_DIR}/scripts/buildsystems/vcpkg.cmake")
    message(STATUS "(MSG) - ${PROJECT_NAME}: INC_VPCKG_DIR is supplied as ${INC_VPCKG_DIR}")
else()
    message(STATUS "(MSG) - ${PROJECT_NAME}: INC_VPCKG_DIR is not supplied, will assume library already include from workstation environment")
endif(INC_VPCKG)
# ########################################################################


# ########################################################################
# reserved options
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
include(GenerateExportHeader)

generate_export_header(${PROJECT_NAME} EXPORT_FILE_NAME ${PROJECT_SOURCE_DIR}/src/prthgcpp/prthgcpp_export.gen.h)

configure_file(
    ${PROJECT_SOURCE_DIR}/src/prthgcpp/prthgcpp_config.h.in
    ${PROJECT_SOURCE_DIR}/src/prthgcpp/prthgcpp_config.gen.h
)
# ########################################################################


# ########################################################################
find_package(jsoncpp CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE JsonCpp::JsonCpp)

find_package(cryptopp CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}  PRIVATE cryptopp::cryptopp)
# ########################################################################


# ########################################################################
add_definitions(-D__PRTHGCPP_MAJOR__=${PRTHGCPP_MAJOR})
add_definitions(-D__PRTHGCPP_MINOR__=${PRTHGCPP_MINOR})
add_definitions(-D__PRTHGCPP_PATCH__=${PRTHGCPP_PATCH})
add_definitions(-D__PRTHGCPP_DATES__=${PRTHGCPP_DATES})
add_definitions(-D__PRTHGCPP_VERSION__=${PRTHGCPP_VERSION})
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
# reserved
# ########################################################################