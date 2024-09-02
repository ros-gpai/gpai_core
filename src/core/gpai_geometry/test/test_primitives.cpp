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

#include <gtest/gtest.h>

#include "gpai_geometry/primitives.hpp"

using gpai::geometry::Point2D;
using gpai::geometry::Line2D;

TEST(gpai_geometry, point2d)
{
  // Test creation, population, and members
  Point2D p1{};

  p1.x(94.67528);
  p1.y(445.98437);

  EXPECT_EQ(p1.x(), 94.67528);
  EXPECT_EQ(p1.y(), 445.98437);

  Point2D p2{3.5, 6.2};

  p2.x(p1.x());
  p2.y(p1.y());

  EXPECT_EQ(p1.x(), p2.x());
  EXPECT_EQ(p1.y(), p2.y());

  // Test operators
  p2 += Point2D(2.6, 9.553);

  EXPECT_EQ(p2.x(), 97.27528);
  EXPECT_EQ(p2.y(), 455.53737);

  Point2D p3{97.27528, 455.53737};

  EXPECT_FALSE(p3 == p1);
  EXPECT_TRUE(p3 != p1);
  EXPECT_TRUE(p3 == p2);
  EXPECT_FALSE(p3 != p2);

  p3 -= p3;

  EXPECT_TRUE(p3.x() == 0.0);
  EXPECT_TRUE(p3.y() == 0.0);

  p3 += p2;

  EXPECT_TRUE(p3 == p2);
  EXPECT_FALSE(p3 != p2);
}

TEST(gpai_geometry, line2d)
{
  // Test creation, population, and members
  Line2D l1{};

  l1.standard(1.0, 2.0, 3.0);

  EXPECT_DOUBLE_EQ(l1.slope(), -0.5);
  EXPECT_DOUBLE_EQ(l1.x_intercept(), -3.0);
  EXPECT_DOUBLE_EQ(l1.y_intercept(), -1.5);
}
