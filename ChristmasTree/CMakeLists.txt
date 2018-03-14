
include (../Modules/gtest.cmake)

add_executable (
  ChristmasTree main.cpp
  )

target_link_libraries (
  ChristmasTree PRIVATE gtest
  )
