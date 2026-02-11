// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from avig_msg:msg/ObjDetect.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__MSG__DETAIL__OBJ_DETECT__TRAITS_HPP_
#define AVIG_MSG__MSG__DETAIL__OBJ_DETECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "avig_msg/msg/detail/obj_detect__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace avig_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjDetect & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: posx
  {
    out << "posx: ";
    rosidl_generator_traits::value_to_yaml(msg.posx, out);
    out << ", ";
  }

  // member: posy
  {
    out << "posy: ";
    rosidl_generator_traits::value_to_yaml(msg.posy, out);
    out << ", ";
  }

  // member: orden
  {
    out << "orden: ";
    rosidl_generator_traits::value_to_yaml(msg.orden, out);
    out << ", ";
  }

  // member: dist
  {
    out << "dist: ";
    rosidl_generator_traits::value_to_yaml(msg.dist, out);
    out << ", ";
  }

  // member: orient
  {
    out << "orient: ";
    rosidl_generator_traits::value_to_yaml(msg.orient, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjDetect & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: posx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posx: ";
    rosidl_generator_traits::value_to_yaml(msg.posx, out);
    out << "\n";
  }

  // member: posy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "posy: ";
    rosidl_generator_traits::value_to_yaml(msg.posy, out);
    out << "\n";
  }

  // member: orden
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orden: ";
    rosidl_generator_traits::value_to_yaml(msg.orden, out);
    out << "\n";
  }

  // member: dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist: ";
    rosidl_generator_traits::value_to_yaml(msg.dist, out);
    out << "\n";
  }

  // member: orient
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orient: ";
    rosidl_generator_traits::value_to_yaml(msg.orient, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjDetect & msg, bool use_flow_style = false)
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
  const avig_msg::msg::ObjDetect & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::msg::ObjDetect & msg)
{
  return avig_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::msg::ObjDetect>()
{
  return "avig_msg::msg::ObjDetect";
}

template<>
inline const char * name<avig_msg::msg::ObjDetect>()
{
  return "avig_msg/msg/ObjDetect";
}

template<>
struct has_fixed_size<avig_msg::msg::ObjDetect>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<avig_msg::msg::ObjDetect>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<avig_msg::msg::ObjDetect>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AVIG_MSG__MSG__DETAIL__OBJ_DETECT__TRAITS_HPP_
