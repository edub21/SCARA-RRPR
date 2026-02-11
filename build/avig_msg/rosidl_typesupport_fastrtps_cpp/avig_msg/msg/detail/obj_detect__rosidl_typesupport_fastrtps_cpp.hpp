// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from avig_msg:msg/ObjDetect.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__MSG__DETAIL__OBJ_DETECT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define AVIG_MSG__MSG__DETAIL__OBJ_DETECT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "avig_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "avig_msg/msg/detail/obj_detect__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace avig_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
cdr_serialize(
  const avig_msg::msg::ObjDetect & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  avig_msg::msg::ObjDetect & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
get_serialized_size(
  const avig_msg::msg::ObjDetect & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
max_serialized_size_ObjDetect(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace avig_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, avig_msg, msg, ObjDetect)();

#ifdef __cplusplus
}
#endif

#endif  // AVIG_MSG__MSG__DETAIL__OBJ_DETECT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
