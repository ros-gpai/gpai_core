cmake_minimum_required(VERSION 3.8)
project(gpai_geometry)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_library(${PROJECT_NAME} SHARED src/primitives.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_compile_definitions(${PROJECT_NAME} PRIVATE "GPAI_GEOMETRY_BUILDING_LIBRARY")

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  ament_auto_add_gtest(primitives_test
    test/test_primitives.cpp
  )
endif()

ament_auto_package()
