# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "RTS_Engine\\CMakeFiles\\RTS_Engine_autogen.dir\\AutogenUsed.txt"
  "RTS_Engine\\CMakeFiles\\RTS_Engine_autogen.dir\\ParseCache.txt"
  "RTS_Engine\\RTS_Engine_autogen"
  )
endif()
