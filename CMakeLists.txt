cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

if(NOT TARGET score_lib_base)
  include("${SCORE_SOURCE_DIR}/cmake/ScoreExternalAddon.cmake")
endif()

project(score_addon_sc LANGUAGES CXX)

# General initialization
score_common_setup()

# Creation of the library
add_library(score_addon_sc
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
