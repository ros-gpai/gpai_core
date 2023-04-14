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

namespace rclcpp_gpai
{

Node::Node(const std::string & node_name, const NodeOptions & options)
: rclcpp::Node(node_name, options)
{
}

const rclcpp::ParameterValue &
Node::declare_parameter(
  const std::string & name,
  const rclcpp::ParameterValue & default_value,
  const rcl_interfaces::msg::ParameterDescriptor & parameter_descriptor,
  bool ignore_override)
{
  try {
    return rclcpp::Node::declare_parameter(
      name,
      default_value,
      parameter_descriptor,
      ignore_override);
  } catch (const rclcpp::exceptions::ParameterAlreadyDeclaredException & ex) {
    RCLCPP_ERROR(this->get_logger(), "Parameter %s already delcared.", name.c_str());
    throw ex;
  } catch (const rclcpp::exceptions::InvalidParametersException & ex) {
    RCLCPP_ERROR(this->get_logger(), "Parameter name %s is invalid.", name.c_str());
    throw ex;
  } catch (const rclcpp::exceptions::InvalidParameterValueException & ex) {
    RCLCPP_ERROR(this->get_logger(), "Failed to set initial value for parameter %s.", name.c_str());
    throw ex;
  } catch (const rclcpp::exceptions::InvalidParameterTypeException & ex) {
    RCLCPP_ERROR(
      this->get_logger(),
      "Default value or override value for parameter %s is incorrect.", name.c_str());
    throw ex;
  }
}

const rclcpp::ParameterValue &
Node::declare_parameter(
  const std::string & name,
  rclcpp::ParameterType type,
  const rcl_interfaces::msg::ParameterDescriptor & parameter_descriptor,
  bool ignore_override)
{
  try {
    return rclcpp::Node::declare_parameter(
      name,
      type,
      parameter_descriptor,
      ignore_override);
  } catch (const rclcpp::exceptions::InvalidParameterTypeException & ex) {
    RCLCPP_ERROR(
      this->get_logger(),
      "Default value or override value for parameter %s is incorrect.", name.c_str());
    throw ex;
  }
}

}  // namespace rclcpp_gpai
