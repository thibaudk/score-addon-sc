cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

if(NOT TARGET score_lib_base)
    include("${SCORE_SOURCE_DIR}/cmake/ScoreExternalAddon.cmake")
endif()

project(score_addon_sc LANGUAGES CXX)

# General initialization
score_common_setup()

set(SC_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/sc/3rdparty/supercollider")

set(SC_AUDIO_API SC_AUDIO_API_PORTAUDIO)

set(CMAKE_MODULE_PATH ${SC_FOLDER}/cmake_modules
    ${CMAKE_MODULE_PATH})

list(APPEND scsynth_sources SC_PortAudio.cpp ${SC_FOLDER}/common/SC_PaUtils.cpp)
add_definitions("-DSC_AUDIO_API=SC_AUDIO_API_PORTAUDIO" ${PORTAUDIO_DEFINITIONS})
include_directories(${PORTAUDIO_INCLUDE_DIRS})

add_subdirectory("${SC_FOLDER}/tools")
include_directories("${SC_FOLDER}/external_libraries/boost_sync/include")
include_directories("${SC_FOLDER}/external_libraries/TLSF-2.4.6/src")

include_directories("${SC_FOLDER}/include/common")
include_directories("${SC_FOLDER}/include/plugin_interface")
include_directories("${SC_FOLDER}/include/server")
include_directories("${SC_FOLDER}/include")
include_directories("${SC_FOLDER}/common")
include_directories("${SC_FOLDER}/server")

## Failed attempt at building libscsynth, done manually for now
#include("${CMAKE_CURRENT_SOURCE_DIR}/sc/3rdparty/supercollider/CMakeLists.txt")

#set(AUDIOAPI "default" CACHE STRING "Audio API to use (one of {default,coreaudio,jack,portaudio,bela})")
#set(CMAKE_SOURCE_DIR ${SC_FOLDER})
#add_subdirectory("${SC_FOLDER}/server")

# Creation of the library
add_library(score_addon_sc
    sc/SCProcess.cpp
    sc/SCProcess.hpp
    sc/sc_protocol.cpp
    sc/sc_protocol.hpp
    sc/Device.cpp
    sc/Device.hpp
    sc/ProtocolFactory.cpp
    sc/ProtocolFactory.hpp
    sc/ProtocolSettingsWidget.cpp
    sc/ProtocolSettingsWidget.hpp
    sc/SpecificSettings.hpp
    sc/SpecificSettingsSerialization.cpp

    score_addon_sc.hpp
    score_addon_sc.cpp
    )

# Link
target_link_libraries(score_addon_sc PUBLIC score_plugin_engine)

# Target-specific options
setup_score_plugin(score_addon_sc)
