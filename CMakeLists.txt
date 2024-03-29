cmake_minimum_required(VERSION 3.9.1)
project(AoC)
set(CMAKE_CXX_STANDARD 20)

OPTION(TWENTYTWO "Build code for 2022" ON)

if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColorReset "${Esc}[m")
  set(Red         "${Esc}[31m")
  set(Green       "${Esc}[32m")
  set(Yellow      "${Esc}[33m")
  set(BoldRed     "${Esc}[1;31m")
  set(BoldYellow  "${Esc}[1;33m")
endif()

if((NOT CMAKE_BUILD_TYPE) OR (${CMAKE_BUILD_TYPE} MATCHES Debug))
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0")
    message("${BoldYellow} Debug Build ${ColorReset}")
elseif(${CMAKE_BUILD_TYPE} MATCHES Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    message("${BoldRed} Release Build ${ColorReset}")
endif()

# Mac install using Homebrew, Windows with Msys2, Unix using Conda
if ((${CMAKE_HOST_SYSTEM_NAME} MATCHES "Windows") OR (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Darwin"))
    set(CONAN_COMMAND "conan")
elseif(${CMAKE_HOST_SYSTEM_NAME} MATCHES "Unix")
    set(CONAN_COMMAND "$ENV{HOME}/.local/bin/conan")
endif()

execute_process(COMMAND ${CONAN_COMMAND} install ${CMAKE_HOME_DIRECTORY}/conanfile.txt -b missing WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

if(TWENTYTWO)
    add_subdirectory(2022)
endif()