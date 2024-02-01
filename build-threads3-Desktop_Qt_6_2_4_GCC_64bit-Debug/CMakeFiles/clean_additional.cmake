# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/threads3_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/threads3_autogen.dir/ParseCache.txt"
  "threads3_autogen"
  )
endif()
