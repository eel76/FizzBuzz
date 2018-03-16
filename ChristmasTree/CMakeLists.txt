
include (../Modules/gtest.cmake)

add_executable (
  ChristmasTree main.cpp catalog.h image.h
  )

target_link_libraries (
  ChristmasTree PRIVATE gtest
  )
