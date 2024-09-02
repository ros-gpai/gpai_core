// Copyright 2024, Electrified Autonomy, LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GPAI_GEOMETRY__VISIBILITY_CONTROL_H_
#define GPAI_GEOMETRY__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define GPAI_GEOMETRY_EXPORT __attribute__ ((dllexport))
    #define GPAI_GEOMETRY_IMPORT __attribute__ ((dllimport))
  #else
    #define GPAI_GEOMETRY_EXPORT __declspec(dllexport)
    #define GPAI_GEOMETRY_IMPORT __declspec(dllimport)
  #endif
  #ifdef GPAI_GEOMETRY_BUILDING_LIBRARY
    #define GPAI_GEOMETRY_PUBLIC GPAI_GEOMETRY_EXPORT
  #else
    #define GPAI_GEOMETRY_PUBLIC GPAI_GEOMETRY_IMPORT
  #endif
  #define GPAI_GEOMETRY_PUBLIC_TYPE GPAI_GEOMETRY_PUBLIC
  #define GPAI_GEOMETRY_LOCAL
#else
  #define GPAI_GEOMETRY_EXPORT __attribute__ ((visibility("default")))
  #define GPAI_GEOMETRY_IMPORT
  #if __GNUC__ >= 4
    #define GPAI_GEOMETRY_PUBLIC __attribute__ ((visibility("default")))
    #define GPAI_GEOMETRY_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define GPAI_GEOMETRY_PUBLIC
    #define GPAI_GEOMETRY_LOCAL
  #endif
  #define GPAI_GEOMETRY_PUBLIC_TYPE
#endif

#endif  // GPAI_GEOMETRY__VISIBILITY_CONTROL_H_
