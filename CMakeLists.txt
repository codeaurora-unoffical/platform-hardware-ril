cmake_minimum_required(VERSION 2.8.9)

project (ril)

# Supported configurations
set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "Release"
  )
set(CMAKE_CONFIGURATION_TYPES ${CMAKE_CONFIGURATION_TYPES} CACHE STRING "Available build configurations." FORCE)

include_directories(BEFORE include)

add_subdirectory( rild )
add_subdirectory( librilutils )
add_subdirectory( libril )

# <--------------------------------------------->
# adding header file install
# <--------------------------------------------->
install( DIRECTORY include/libril DESTINATION include )
install( DIRECTORY include/telephony DESTINATION include )

