# This file was generated by Jucer2Reprojucer from "vst.jucer"

cmake_minimum_required(VERSION 3.4)

project("vst")


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../frut/prefix/FRUT/cmake")
include(Reprojucer)

set(NAME
  "vst"
)

set(vst_jucer_FILE
  "${CMAKE_CURRENT_LIST_DIR}/vst.jucer"
)


jucer_project_begin(
  JUCER_VERSION "5.4.7"
  PROJECT_FILE "${vst_jucer_FILE}"
  PROJECT_ID "ZFG9Mk"
)

jucer_project_settings(
  PROJECT_NAME "${NAME}"
  PROJECT_VERSION "1.0.0"
  REPORT_JUCE_APP_USAGE ON # Required for closed source applications without an Indie or Pro JUCE license
  DISPLAY_THE_JUCE_SPLASH_SCREEN ON # Required for closed source applications without an Indie or Pro JUCE license
  PROJECT_TYPE "Audio Plug-in"
  BUNDLE_IDENTIFIER "com.yourcompany.vst"
  CXX_LANGUAGE_STANDARD "C++14"
)

jucer_audio_plugin_settings(
  PLUGIN_FORMATS
    "VST3"
    "AU"
    "Standalone"
  # PLUGIN_CHARACTERISTICS
  PLUGIN_NAME "${NAME}"
  PLUGIN_DESCRIPTION "An audio plugin..."
  PLUGIN_MANUFACTURER "yourcompany"
  PLUGIN_MANUFACTURER_CODE "Manu"
  PLUGIN_CODE "Zfg9"
  # PLUGIN_CHANNEL_CONFIGURATIONS
  PLUGIN_AAX_IDENTIFIER "com.yourcompany.vst"
  PLUGIN_AU_EXPORT_PREFIX "vstAU"
  PLUGIN_AU_MAIN_TYPE "kAudioUnitType_Effect"
  PLUGIN_VST3_CATEGORY
    "Fx"
  PLUGIN_RTAS_CATEGORY
    "ePlugInCategory_None"
  PLUGIN_AAX_CATEGORY
    "AAX_ePlugInCategory_None"
  PLUGIN_VST_LEGACY_CATEGORY "kPlugCategEffect"
)

jucer_project_files("vst/Source"
# Compile   Xcode     Binary    File
#           Resource  Resource
  x         .         .         "Source/CoreProcessor.cpp"
  .         .         .         "Source/CoreProcessor.h"
  x         .         .         "Source/CoreEditor.cpp"
  .         .         .         "Source/CoreEditor.h"
  # x         .         .         "Source/dsp/DistortionProcessor.h"
  # x         .         .         "Source/dsp/GainProcessor.h"
)

jucer_project_module(
  juce_audio_basics
  PATH "../juce/modules"
)

jucer_project_module(
  juce_audio_devices
  PATH "../juce/modules"
  # JUCE_USE_WINRT_MIDI
  # JUCE_ASIO
  # JUCE_WASAPI
  # JUCE_WASAPI_EXCLUSIVE
  # JUCE_DIRECTSOUND
  # JUCE_ALSA
  # JUCE_JACK
  # JUCE_BELA
  # JUCE_USE_ANDROID_OBOE
  # JUCE_USE_ANDROID_OPENSLES
  # JUCE_DISABLE_AUDIO_MIXING_WITH_OTHER_APPS
)

jucer_project_module(
  juce_audio_formats
  PATH "../juce/modules"
  # JUCE_USE_FLAC
  # JUCE_USE_OGGVORBIS
  # JUCE_USE_MP3AUDIOFORMAT
  # JUCE_USE_LAME_AUDIO_FORMAT
  # JUCE_USE_WINDOWS_MEDIA_FORMAT
)

jucer_project_module(
  juce_audio_plugin_client
  PATH "../juce/modules"
  JUCE_VST3_CAN_REPLACE_VST2 OFF
  # JUCE_FORCE_USE_LEGACY_PARAM_IDS
  # JUCE_FORCE_LEGACY_PARAMETER_AUTOMATION_TYPE
  # JUCE_USE_STUDIO_ONE_COMPATIBLE_PARAMETERS
  # JUCE_AU_WRAPPERS_SAVE_PROGRAM_STATES
  # JUCE_STANDALONE_FILTER_WINDOW_USE_KIOSK_MODE
)

jucer_project_module(
  juce_audio_processors
  PATH "../juce/modules"
  # JUCE_PLUGINHOST_VST
  # JUCE_PLUGINHOST_VST3
  # JUCE_PLUGINHOST_AU
  # JUCE_PLUGINHOST_LADSPA
)

jucer_project_module(
  juce_audio_utils
  PATH "../juce/modules"
  # JUCE_USE_CDREADER
  # JUCE_USE_CDBURNER
)

jucer_project_module(
  juce_core
  PATH "../juce/modules"
  # JUCE_FORCE_DEBUG
  # JUCE_LOG_ASSERTIONS
  # JUCE_CHECK_MEMORY_LEAKS
  # JUCE_DONT_AUTOLINK_TO_WIN32_LIBRARIES
  # JUCE_INCLUDE_ZLIB_CODE
  # JUCE_USE_CURL
  # JUCE_LOAD_CURL_SYMBOLS_LAZILY
  # JUCE_CATCH_UNHANDLED_EXCEPTIONS
  # JUCE_ALLOW_STATIC_NULL_VARIABLES
  JUCE_STRICT_REFCOUNTEDPOINTER ON
)

jucer_project_module(
  juce_cryptography
  PATH "../juce/modules"
)

jucer_project_module(
  juce_data_structures
  PATH "../juce/modules"
)

jucer_project_module(
  juce_dsp
  PATH "../juce/modules"
)

jucer_project_module(
  juce_events
  PATH "../juce/modules"
  # JUCE_EXECUTE_APP_SUSPEND_ON_BACKGROUND_TASK
)

jucer_project_module(
  juce_graphics
  PATH "../juce/modules"
  # JUCE_USE_COREIMAGE_LOADER
  # JUCE_USE_DIRECTWRITE
  # JUCE_DISABLE_COREGRAPHICS_FONT_SMOOTHING
)

jucer_project_module(
  juce_gui_basics
  PATH "../juce/modules"
  # JUCE_ENABLE_REPAINT_DEBUGGING
  # JUCE_USE_XRANDR
  # JUCE_USE_XINERAMA
  # JUCE_USE_XSHM
  # JUCE_USE_XRENDER
  # JUCE_USE_XCURSOR
  # JUCE_WIN_PER_MONITOR_DPI_AWARE
)

jucer_project_module(
  juce_gui_extra
  PATH "../juce/modules"
  # JUCE_WEB_BROWSER
  # JUCE_ENABLE_LIVE_CONSTANT_EDITOR
)

jucer_project_module(
  juce_opengl
  PATH "../juce/modules"
)

jucer_export_target(
  "Xcode (MacOSX)"
)

jucer_export_target_configuration(
  "Xcode (MacOSX)"
  NAME "Debug"
  DEBUG_MODE ON
)

jucer_export_target_configuration(
  "Xcode (MacOSX)"
  NAME "Release"
  DEBUG_MODE OFF
)

jucer_project_end()
