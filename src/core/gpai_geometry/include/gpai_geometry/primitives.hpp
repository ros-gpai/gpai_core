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

#ifndef GPAI_GEOMETRY__PRIMITIVES_HPP_
#define GPAI_GEOMETRY__PRIMITIVES_HPP_

#include "gpai_geometry/visibility_control.h"

namespace gpai
{
namespace geometry
{

class Point3D;

// ---------- Point2D ---------- //

class Point2D
{
public:
  Point2D();
  Point2D(double x, double y);

  friend constexpr bool operator==(const Point2D & lhs, const Point2D & rhs) noexcept;
  friend constexpr bool operator!=(const Point2D & lhs, const Point2D & rhs) noexcept;

  Point2D & operator+=(const Point2D & other) noexcept;
  Point2D & operator-=(const Point2D & other) noexcept;

  double x() const noexcept;
  double y() const noexcept;

  void x(double new_x) noexcept;
  void y(double new_y) noexcept;

  void rotate_around_origin(double angle) noexcept;
  void rotate_around_point(double angle, double x, double y) noexcept;

  Point3D to_3d();

private:
  double x_, y_;
};

constexpr bool operator==(const Point2D & lhs, const Point2D & rhs) noexcept
{
  return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}

constexpr bool operator!=(const Point2D & lhs, const Point2D & rhs) noexcept
{
  return !(lhs == rhs);
}

inline Point2D operator+(const Point2D & lhs, const Point2D & rhs) noexcept;
inline Point2D operator-(const Point2D & lhs, const Point2D & rhs) noexcept;

// ---------- Line2D ---------- //

class Line2D
{
public:
  Line2D();

  // @brief Standard form constructor
  Line2D(double a, double b, double c);

  // @brief Two-point constructor
  Line2D(const Point2D & p1, const Point2D & p2);

  friend constexpr bool operator==(const Line2D & lhs, const Line2D & rhs) noexcept;
  friend constexpr bool operator!=(const Line2D & lhs, const Line2D & rhs) noexcept;

  void standard(double a, double b, double c) noexcept;
  void two_points(const Point2D & p1, const Point2D & p2) noexcept;

  double slope() noexcept;
  double x_intercept() noexcept;
  double y_intercept() noexcept;

private:
  double a_, b_, c_;
};

constexpr bool operator==(const Line2D & lhs, const Line2D & rhs) noexcept
{
  return lhs.a_ == rhs.a_ && lhs.b_ == rhs.b_ && lhs.c_ == rhs.c_;
}

constexpr bool operator!=(const Line2D & lhs, const Line2D & rhs) noexcept
{
  return !(lhs == rhs);
}

// ---------- Point3D ---------- //

class Point3D
{
public:
  Point3D();
  Point3D(double x, double y, double z);

  friend constexpr bool operator==(const Point3D & lhs, const Point3D & rhs) noexcept;
  friend constexpr bool operator!=(const Point3D & lhs, const Point3D & rhs) noexcept;

  Point3D & operator+=(const Point3D & other) noexcept;
  Point3D & operator-=(const Point3D & other) noexcept;

  double x() const noexcept;
  double y() const noexcept;
  double z() const noexcept;

  void x(double new_x) noexcept;
  void y(double new_y) noexcept;
  void z(double new_z) noexcept;

  // void rotate_around_origin(double angle) noexcept;
  // void rotate_around_point(double angle, double x, double y, double z) noexcept;

  Point2D to_2d();

private:
  double x_, y_, z_;
};

constexpr bool operator==(const Point3D & lhs, const Point3D & rhs) noexcept
{
  return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_ && lhs.z_ == rhs.z_;
}

constexpr bool operator!=(const Point3D & lhs, const Point3D & rhs) noexcept
{
  return !(lhs == rhs);
}

inline Point3D operator+(const Point3D & lhs, const Point3D & rhs) noexcept;
inline Point3D operator-(const Point3D & lhs, const Point3D & rhs) noexcept;

}  // namespace geometry
}  // namespace gpai

#endif  // GPAI_GEOMETRY__PRIMITIVES_HPP_
