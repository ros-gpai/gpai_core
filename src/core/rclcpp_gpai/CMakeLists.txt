cmake_minimum_required(VERSION 3.8)
project(rclcpp_gpai)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # About -Wno-sign-conversion: With Clang, -Wconversion implies -Wsign-conversion. There are a number of
  # implicit sign conversions in rclcpp and gtest.cc, see https://ci.ros2.org/job/ci_osx/9265/.
  # Hence disabling -Wsign-conversion for now until all those have eventually been fixed.
  # (from https://github.com/ros2/rclcpp/pull/1188#issuecomment-650229140)
  add_compile_options(-Wall -Wextra -Wconversion -Wno-sign-conversion -Wpedantic -Wnon-virtual-dtor -Woverloaded-virtual)
endif()

set(${PROJECT_NAME}_SRCS
  src/rclcpp_gpai.cpp
)

# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SRCS})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

if(WIN32)
  target_compile_definitions(${PROJECT_NAME} PUBLIC "_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS")
endif()

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(${PROJECT_NAME}
  PRIVATE "RCLCPP_BUILDING_LIBRARY")

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package()

ament_generate_version_header(${PROJECT_NAME})
