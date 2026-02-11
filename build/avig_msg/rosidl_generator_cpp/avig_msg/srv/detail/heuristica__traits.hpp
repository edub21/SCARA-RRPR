// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from avig_msg:srv/Heuristica.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__SRV__DETAIL__HEURISTICA__TRAITS_HPP_
#define AVIG_MSG__SRV__DETAIL__HEURISTICA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "avig_msg/srv/detail/heuristica__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'tags_in'
#include "avig_msg/msg/detail/april_tag_pixel_array__traits.hpp"

namespace avig_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const Heuristica_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: tags_in
  {
    out << "tags_in: ";
    to_flow_style_yaml(msg.tags_in, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Heuristica_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tags_in
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tags_in:\n";
    to_block_style_yaml(msg.tags_in, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Heuristica_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace avig_msg

namespace rosidl_generator_traits
{

[[deprecated("use avig_msg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const avig_msg::srv::Heuristica_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::srv::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::srv::Heuristica_Request & msg)
{
  return avig_msg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::srv::Heuristica_Request>()
{
  return "avig_msg::srv::Heuristica_Request";
}

template<>
inline const char * name<avig_msg::srv::Heuristica_Request>()
{
  return "avig_msg/srv/Heuristica_Request";
}

template<>
struct has_fixed_size<avig_msg::srv::Heuristica_Request>
  : std::integral_constant<bool, has_fixed_size<avig_msg::msg::AprilTagPixelArray>::value> {};

template<>
struct has_bounded_size<avig_msg::srv::Heuristica_Request>
  : std::integral_constant<bool, has_bounded_size<avig_msg::msg::AprilTagPixelArray>::value> {};

template<>
struct is_message<avig_msg::srv::Heuristica_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'tag_out'
#include "avig_msg/msg/detail/april_tag_pixel__traits.hpp"

namespace avig_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const Heuristica_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: tag_out
  {
    out << "tag_out: ";
    to_flow_style_yaml(msg.tag_out, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Heuristica_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tag_out
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tag_out:\n";
    to_block_style_yaml(msg.tag_out, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Heuristica_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace avig_msg

namespace rosidl_generator_traits
{

[[deprecated("use avig_msg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const avig_msg::srv::Heuristica_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::srv::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::srv::Heuristica_Response & msg)
{
  return avig_msg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::srv::Heuristica_Response>()
{
  return "avig_msg::srv::Heuristica_Response";
}

template<>
inline const char * name<avig_msg::srv::Heuristica_Response>()
{
  return "avig_msg/srv/Heuristica_Response";
}

template<>
struct has_fixed_size<avig_msg::srv::Heuristica_Response>
  : std::integral_constant<bool, has_fixed_size<avig_msg::msg::AprilTagPixel>::value> {};

template<>
struct has_bounded_size<avig_msg::srv::Heuristica_Response>
  : std::integral_constant<bool, has_bounded_size<avig_msg::msg::AprilTagPixel>::value> {};

template<>
struct is_message<avig_msg::srv::Heuristica_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<avig_msg::srv::Heuristica>()
{
  return "avig_msg::srv::Heuristica";
}

template<>
inline const char * name<avig_msg::srv::Heuristica>()
{
  return "avig_msg/srv/Heuristica";
}

template<>
struct has_fixed_size<avig_msg::srv::Heuristica>
  : std::integral_constant<
    bool,
    has_fixed_size<avig_msg::srv::Heuristica_Request>::value &&
    has_fixed_size<avig_msg::srv::Heuristica_Response>::value
  >
{
};

template<>
struct has_bounded_size<avig_msg::srv::Heuristica>
  : std::integral_constant<
    bool,
    has_bounded_size<avig_msg::srv::Heuristica_Request>::value &&
    has_bounded_size<avig_msg::srv::Heuristica_Response>::value
  >
{
};

template<>
struct is_service<avig_msg::srv::Heuristica>
  : std::true_type
{
};

template<>
struct is_service_request<avig_msg::srv::Heuristica_Request>
  : std::true_type
{
};

template<>
struct is_service_response<avig_msg::srv::Heuristica_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AVIG_MSG__SRV__DETAIL__HEURISTICA__TRAITS_HPP_
