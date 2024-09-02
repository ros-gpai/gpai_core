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

#include "gpai_geometry/primitives.hpp"

#include <cmath>
#include <limits>

namespace gpai
{
namespace geometry
{

// ---------- Point2D ---------- //

Point2D::Point2D()
: x_{}, y_{}
{
}

Point2D::Point2D(double x, double y)
: x_{x}, y_{y}
{
}

Point2D & Point2D::operator+=(const Point2D & other) noexcept
{
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}

Point2D & Point2D::operator-=(const Point2D & other) noexcept
{
  x_ -= other.x_;
  y_ -= other.y_;
  return *this;
}

double Point2D::x() const noexcept
{
  return x_;
}

double Point2D::y() const noexcept
{
  return y_;
}

void Point2D::x(double new_x) noexcept
{
  x_ = new_x;
}

void Point2D::y(double new_y) noexcept
{
  y_ = new_y;
}

void Point2D::rotate_around_origin(double angle) noexcept
{
  double old_x = x_;
  x_ = x_ * std::cos(angle) - y_ * std::sin(angle);
  y_ = y_ * std::cos(angle) + old_x * std::sin(angle);
}

void Point2D::rotate_around_point(double angle, double x, double y) noexcept
{
  double old_x = x_;
  x_ = std::cos(angle) * (x_ - x) - std::sin(angle) * (y_ - y) + x;
  y_ = std::sin(angle) * (old_x - x) + std::cos(angle) * (y_ - y) + y;
}

inline Point2D operator+(const Point2D & lhs, const Point2D & rhs) noexcept
{
  Point2D result = lhs;
  result += rhs;
  return result;
}

inline Point2D operator-(const Point2D & lhs, const Point2D & rhs) noexcept
{
  Point2D result = lhs;
  result -= rhs;
  return result;
}

// ---------- Line2D ---------- //

Line2D::Line2D()
: a_{}, b_{}, c_{}
{
}

Line2D::Line2D(double a, double b, double c)
: a_{a}, b_{b}, c_{c}
{
}

Line2D::Line2D(const Point2D & p1, const Point2D & p2)
{
  two_points(p1, p2);
}

void Line2D::standard(double a, double b, double c) noexcept
{
  a_ = a;
  b_ = b;
  c_ = c;
}

void Line2D::two_points(const Point2D & p1, const Point2D & p2) noexcept
{
  a_ = p2.y() - p1.y();
  b_ = p1.x() - p2.x();
  c_ = p1.y() * (p2.x() - p1.x()) - (p2.y() - p1.y()) * p1.x();
}

double Line2D::slope() noexcept
{
  if (std::fabs(b_) < std::numeric_limits<double>::epsilon()) {
    return 0.0;
  }

  return -a_ / b_;
}

double Line2D::x_intercept() noexcept
{
  if (std::fabs(a_) < std::numeric_limits<double>::epsilon()) {
    return 0.0;
  }

  return -c_ / a_;
}

double Line2D::y_intercept() noexcept
{
  if (std::fabs(b_) < std::numeric_limits<double>::epsilon()) {
    return 0.0;
  }

  return -c_ / b_;
}

}  // namespace geometry
}  // namespace gpai
