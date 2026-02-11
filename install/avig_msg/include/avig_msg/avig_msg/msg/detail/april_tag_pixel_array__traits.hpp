// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from avig_msg:msg/AprilTagPixelArray.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__TRAITS_HPP_
#define AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "avig_msg/msg/detail/april_tag_pixel_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'tags'
#include "avig_msg/msg/detail/april_tag_pixel__traits.hpp"

namespace avig_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const AprilTagPixelArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: tags
  {
    if (msg.tags.size() == 0) {
      out << "tags: []";
    } else {
      out << "tags: [";
      size_t pending_items = msg.tags.size();
      for (auto item : msg.tags) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AprilTagPixelArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tags.size() == 0) {
      out << "tags: []\n";
    } else {
      out << "tags:\n";
      for (auto item : msg.tags) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AprilTagPixelArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace avig_msg

namespace rosidl_generator_traits
{

[[deprecated("use avig_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const avig_msg::msg::AprilTagPixelArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::msg::AprilTagPixelArray & msg)
{
  return avig_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::msg::AprilTagPixelArray>()
{
  return "avig_msg::msg::AprilTagPixelArray";
}

template<>
inline const char * name<avig_msg::msg::AprilTagPixelArray>()
{
  return "avig_msg/msg/AprilTagPixelArray";
}

template<>
struct has_fixed_size<avig_msg::msg::AprilTagPixelArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<avig_msg::msg::AprilTagPixelArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<avig_msg::msg::AprilTagPixelArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__TRAITS_HPP_
