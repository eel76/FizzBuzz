
add_executable (
  FizzBuzz
  main.cpp
  game.h
  range.h
  )

target_link_libraries (
  FizzBuzz PRIVATE Catch
  )
