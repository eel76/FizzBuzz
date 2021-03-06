if (TARGET gtest)
  return ()
endif ()

include (ExternalProject)

ExternalProject_Add (gtest-build
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.8.0
  GIT_PROGRESS true
  GIT_SHALLOW true
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/googletest
  UPDATE_COMMAND ""
  CMAKE_ARGS -Dgtest_force_shared_crt=ON "-DCMAKE_DEBUG_POSTFIX="
  UPDATE_COMMAND ""
  INSTALL_COMMAND ""
)

ExternalProject_Get_Property (gtest-build source_dir)
ExternalProject_Get_Property (gtest-build binary_dir)

add_library (gtest STATIC IMPORTED)

file (MAKE_DIRECTORY "${source_dir}/googletest/include")
set_property (TARGET gtest PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${source_dir}/googletest/include")
set_property (TARGET gtest PROPERTY IMPORTED_LOCATION "${binary_dir}/googlemock/gtest/${CMAKE_CFG_INTDIR}/${CMAKE_STATIC_LIBRARY_PREFIX}gtest${CMAKE_STATIC_LIBRARY_SUFFIX}")
set_property (TARGET gtest PROPERTY IMPORTED_LOCATION_DEBUG "${binary_dir}/googlemock/gtest/${CMAKE_CFG_INTDIR}/${CMAKE_STATIC_LIBRARY_PREFIX}gtestd${CMAKE_STATIC_LIBRARY_SUFFIX}")

add_dependencies (gtest gtest-build)
