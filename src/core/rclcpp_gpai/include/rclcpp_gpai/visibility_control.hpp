// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RCLCPP_GPAI__VISIBILITY_CONTROL_HPP_
#define RCLCPP_GPAI__VISIBILITY_CONTROL_HPP_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define RCLCPP_GPAI_EXPORT __attribute__ ((dllexport))
    #define RCLCPP_GPAI_IMPORT __attribute__ ((dllimport))
  #else
    #define RCLCPP_GPAI_EXPORT __declspec(dllexport)
    #define RCLCPP_GPAI_IMPORT __declspec(dllimport)
  #endif
  #ifdef RCLCPP_GPAI_BUILDING_LIBRARY
    #define RCLCPP_GPAI_PUBLIC RCLCPP_GPAI_EXPORT
  #else
    #define RCLCPP_GPAI_PUBLIC RCLCPP_GPAI_IMPORT
  #endif
  #define RCLCPP_GPAI_PUBLIC_TYPE RCLCPP_GPAI_PUBLIC
  #define RCLCPP_GPAI_LOCAL
#else
  #define RCLCPP_GPAI_EXPORT __attribute__ ((visibility("default")))
  #define RCLCPP_GPAI_IMPORT
  #if __GNUC__ >= 4
    #define RCLCPP_GPAI_PUBLIC __attribute__ ((visibility("default")))
    #define RCLCPP_GPAI_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define RCLCPP_GPAI_PUBLIC
    #define RCLCPP_GPAI_LOCAL
  #endif
  #define RCLCPP_GPAI_PUBLIC_TYPE
#endif

#endif  // RCLCPP_GPAI__VISIBILITY_CONTROL_HPP_
