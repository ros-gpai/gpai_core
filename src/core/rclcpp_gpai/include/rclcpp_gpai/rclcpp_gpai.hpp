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

#ifndef RCLCPP_GPAI__RCLCPP_GPAI_HPP_
#define RCLCPP_GPAI__RCLCPP_GPAI_HPP_

#include <map>
#include <string>
#include <utility>
#include <vector>

#include <rclcpp/rclcpp.hpp>

#include "rclcpp_gpai/visibility_control.hpp"

using rclcpp::NodeOptions;
using rclcpp::ParameterTypeException;
using rclcpp::ParameterValue;

namespace rclcpp_gpai
{

class Node : public rclcpp::Node
{
public:
  /// Create a new node with the specified name.
  /**
   * \param[in] node_name Name of the node.
   * \param[in] options Additional options to control creation of the node.
   * \throws InvalidNamespaceError if the namespace is invalid
   */
  RCLCPP_GPAI_PUBLIC
  explicit Node(
    const std::string & node_name,
    const NodeOptions & options = NodeOptions());

  /// Declare and initialize a parameter, return the effective value.
  /**
   * This method is used to declare that a parameter exists on this node.
   * If, at run-time, the user has provided an initial value then it will be
   * set in this method, otherwise the given default_value will be set.
   * In either case, the resulting value is returned, whether or not it is
   * based on the default value or the user provided initial value.
   *
   * If no parameter_descriptor is given, then the default values from the
   * message definition will be used, e.g. read_only will be false.
   *
   * The name and type in the given rcl_interfaces::msg::ParameterDescriptor
   * are ignored, and should be specified using the name argument to this
   * function and the default value's type instead.
   *
   * If `ignore_override` is `true`, the parameter override will be ignored.
   *
   * This method, if successful, will result in any callback registered with
   * add_on_set_parameters_callback to be called.
   * If that callback prevents the initial value for the parameter from being
   * set then rclcpp::exceptions::InvalidParameterValueException is thrown.
   *
   * The returned reference will remain valid until the parameter is
   * undeclared.
   *
   * \param[in] name The name of the parameter.
   * \param[in] default_value An initial value to be used if at run-time user
   *   did not override it.
   * \param[in] parameter_descriptor An optional, custom description for
   *   the parameter.
   * \param[in] ignore_override When `true`, the parameter override is ignored.
   *    Default to `false`.
   * \return A const reference to the value of the parameter.
   * \throws rclcpp::exceptions::ParameterAlreadyDeclaredException if parameter
   *   has already been declared.
   * \throws rclcpp::exceptions::InvalidParametersException if a parameter
   *   name is invalid.
   * \throws rclcpp::exceptions::InvalidParameterValueException if initial
   *   value fails to be set.
   * \throws rclcpp::exceptions::InvalidParameterTypeException
   *   if the type of the default value or override is wrong.
   */
  RCLCPP_GPAI_PUBLIC
  const ParameterValue &
  declare_parameter(
    const std::string & name,
    const ParameterValue & default_value,
    const rcl_interfaces::msg::ParameterDescriptor & parameter_descriptor =
    rcl_interfaces::msg::ParameterDescriptor(),
    bool ignore_override = false);

  /// Declare and initialize a parameter, return the effective value.
  /**
   * Same as the previous one, but a default value is not provided and the user
   * must provide a parameter override of the correct type.
   *
   * \param[in] name The name of the parameter.
   * \param[in] type Desired type of the parameter, which will enforced at runtime.
   * \param[in] parameter_descriptor An optional, custom description for
   *   the parameter.
   * \param[in] ignore_override When `true`, the parameter override is ignored.
   *    Default to `false`.
   * \return A const reference to the value of the parameter.
   * \throws Same as the previous overload taking a default value.
   * \throws rclcpp::exceptions::InvalidParameterTypeException
   *   if an override is not provided or the provided override is of the wrong type.
   */
  RCLCPP_GPAI_PUBLIC
  const ParameterValue &
  declare_parameter(
    const std::string & name,
    rclcpp::ParameterType type,
    const rcl_interfaces::msg::ParameterDescriptor & parameter_descriptor =
    rcl_interfaces::msg::ParameterDescriptor{},
    bool ignore_override = false);

  /// Declare and initialize a parameter with a type.
  /**
   * See the non-templated declare_parameter() on this class for details.
   *
   * If the type of the default value, and therefore also the type of return
   * value, differs from the initial value provided in the node options, then
   * a rclcpp::exceptions::InvalidParameterTypeException may be thrown.
   * To avoid this, use the declare_parameter() method which returns an
   * rclcpp::ParameterValue instead.
   *
   * Note, this method cannot return a const reference, because extending the
   * lifetime of a temporary only works recursively with member initializers,
   * and cannot be extended to members of a class returned.
   * The return value of this class is a copy of the member of a ParameterValue
   * which is returned by the other version of declare_parameter().
   * See also:
   *
   *   - https://en.cppreference.com/w/cpp/language/lifetime
   *   - https://herbsutter.com/2008/01/01/gotw-88-a-candidate-for-the-most-important-const/
   *   - https://www.youtube.com/watch?v=uQyT-5iWUow (cppnow 2018 presentation)
   */
  template<typename ParameterT>
  auto
  declare_parameter(
    const std::string & name,
    const ParameterT & default_value,
    const rcl_interfaces::msg::ParameterDescriptor & parameter_descriptor =
    rcl_interfaces::msg::ParameterDescriptor(),
    bool ignore_override = false)
  {
    try {
      return this->declare_parameter(
        name,
        ParameterValue(default_value),
        parameter_descriptor,
        ignore_override
      ).get<ParameterT>();
    } catch (const ParameterTypeException & ex) {
      throw rclcpp::exceptions::InvalidParameterTypeException(name, ex.what());
    }
  }

  /// Declare and initialize a parameter with a type.
  /**
   * See the non-templated declare_parameter() on this class for details.
   */
  template<typename ParameterT>
  auto
  declare_parameter(
    const std::string & name,
    const rcl_interfaces::msg::ParameterDescriptor & parameter_descriptor =
    rcl_interfaces::msg::ParameterDescriptor(),
    bool ignore_override = false)
  {
    // get advantage of parameter value template magic to get
    // the correct rclcpp::ParameterType from ParameterT
    ParameterValue value{ParameterT{}};
    try {
      return this->declare_parameter(
        name,
        value.get_type(),
        parameter_descriptor,
        ignore_override
      ).get<ParameterT>();
    } catch (const ParameterTypeException &) {
      throw rclcpp::exceptions::UninitializedStaticallyTypedParameterException(name);
    }
  }

  /// Declare and initialize several parameters with the same namespace and type.
  /**
   * For each key in the map, a parameter with a name of "namespace.key"
   * will be set to the value in the map.
   * The resulting value for each declared parameter will be returned.
   *
   * The name expansion is naive, so if you set the namespace to be "foo.",
   * then the resulting parameter names will be like "foo..key".
   * However, if the namespace is an empty string, then no leading '.' will be
   * placed before each key, which would have been the case when naively
   * expanding "namespace.key".
   * This allows you to declare several parameters at once without a namespace.
   *
   * The map contains default values for parameters.
   * There is another overload which takes the std::pair with the default value
   * and descriptor.
   *
   * If `ignore_overrides` is `true`, all the overrides of the parameters declared
   * by the function call will be ignored.
   *
   * This method, if successful, will result in any callback registered with
   * add_on_set_parameters_callback to be called, once for each parameter.
   * If that callback prevents the initial value for any parameter from being
   * set then rclcpp::exceptions::InvalidParameterValueException is thrown.
   *
   * \param[in] namespace_ The namespace in which to declare the parameters.
   * \param[in] parameters The parameters to set in the given namespace.
   * \param[in] ignore_overrides When `true`, the parameters overrides are ignored.
   *    Default to `false`.
   * \throws rclcpp::exceptions::ParameterAlreadyDeclaredException if parameter
   *   has already been declared.
   * \throws rclcpp::exceptions::InvalidParametersException if a parameter
   *   name is invalid.
   * \throws rclcpp::exceptions::InvalidParameterValueException if initial
   *   value fails to be set.
   */
  template<typename ParameterT>
  std::vector<ParameterT>
  declare_parameters(
    const std::string & namespace_,
    const std::map<std::string, ParameterT> & parameters,
    bool ignore_overrides = false)
  {
    std::vector<ParameterT> result;
    std::string normalized_namespace = namespace_.empty() ? "" : (namespace_ + ".");
    std::transform(
      parameters.begin(), parameters.end(), std::back_inserter(result),
      [this, &normalized_namespace, ignore_overrides](auto element) {
        return this->declare_parameter(
          normalized_namespace + element.first,
          element.second,
          rcl_interfaces::msg::ParameterDescriptor(),
          ignore_overrides);
      }
    );
    return result;
  }

  /// Declare and initialize several parameters with the same namespace and type.
  /**
   * This version will take a map where the value is a pair, with the default
   * parameter value as the first item and a parameter descriptor as the second.
   *
   * See the simpler declare_parameters() on this class for more details.
   */
  template<typename ParameterT>
  std::vector<ParameterT>
  declare_parameters(
    const std::string & namespace_,
    const std::map<
      std::string,
      std::pair<ParameterT, rcl_interfaces::msg::ParameterDescriptor>
    > & parameters,
    bool ignore_overrides = false)
  {
    std::vector<ParameterT> result;
    std::string normalized_namespace = namespace_.empty() ? "" : (namespace_ + ".");
    std::transform(
      parameters.begin(), parameters.end(), std::back_inserter(result),
      [this, &normalized_namespace, ignore_overrides](auto element) {
        return static_cast<ParameterT>(
          this->declare_parameter(
            normalized_namespace + element.first,
            element.second.first,
            element.second.second,
            ignore_overrides)
        );
      }
    );
    return result;
  }
};

}  // namespace rclcpp_gpai

#endif  // RCLCPP_GPAI__RCLCPP_GPAI_HPP_
