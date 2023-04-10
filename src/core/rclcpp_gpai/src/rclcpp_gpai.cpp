// Copyright 2023 The GPAI Contributors
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

#include "rclcpp_gpai/rclcpp_gpai.hpp"

#include <string>

using rclcpp::NodeOptions;

namespace gpai
{

Node::Node(const std::string & node_name, const NodeOptions & options)
: rclcpp::Node(node_name, options)
{
}

}  // namespace gpai
