// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from avig_msg:msg/AprilTagPixelArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "avig_msg/msg/detail/april_tag_pixel_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace avig_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void AprilTagPixelArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) avig_msg::msg::AprilTagPixelArray(_init);
}

void AprilTagPixelArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<avig_msg::msg::AprilTagPixelArray *>(message_memory);
  typed_message->~AprilTagPixelArray();
}

size_t size_function__AprilTagPixelArray__tags(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<avig_msg::msg::AprilTagPixel> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AprilTagPixelArray__tags(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<avig_msg::msg::AprilTagPixel> *>(untyped_member);
  return &member[index];
}

void * get_function__AprilTagPixelArray__tags(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<avig_msg::msg::AprilTagPixel> *>(untyped_member);
  return &member[index];
}

void fetch_function__AprilTagPixelArray__tags(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const avig_msg::msg::AprilTagPixel *>(
    get_const_function__AprilTagPixelArray__tags(untyped_member, index));
  auto & value = *reinterpret_cast<avig_msg::msg::AprilTagPixel *>(untyped_value);
  value = item;
}

void assign_function__AprilTagPixelArray__tags(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<avig_msg::msg::AprilTagPixel *>(
    get_function__AprilTagPixelArray__tags(untyped_member, index));
  const auto & value = *reinterpret_cast<const avig_msg::msg::AprilTagPixel *>(untyped_value);
  item = value;
}

void resize_function__AprilTagPixelArray__tags(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<avig_msg::msg::AprilTagPixel> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AprilTagPixelArray_message_member_array[1] = {
  {
    "tags",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<avig_msg::msg::AprilTagPixel>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(avig_msg::msg::AprilTagPixelArray, tags),  // bytes offset in struct
    nullptr,  // default value
    size_function__AprilTagPixelArray__tags,  // size() function pointer
    get_const_function__AprilTagPixelArray__tags,  // get_const(index) function pointer
    get_function__AprilTagPixelArray__tags,  // get(index) function pointer
    fetch_function__AprilTagPixelArray__tags,  // fetch(index, &value) function pointer
    assign_function__AprilTagPixelArray__tags,  // assign(index, value) function pointer
    resize_function__AprilTagPixelArray__tags  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AprilTagPixelArray_message_members = {
  "avig_msg::msg",  // message namespace
  "AprilTagPixelArray",  // message name
  1,  // number of fields
  sizeof(avig_msg::msg::AprilTagPixelArray),
  AprilTagPixelArray_message_member_array,  // message members
  AprilTagPixelArray_init_function,  // function to initialize message memory (memory has to be allocated)
  AprilTagPixelArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AprilTagPixelArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AprilTagPixelArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace avig_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<avig_msg::msg::AprilTagPixelArray>()
{
  return &::avig_msg::msg::rosidl_typesupport_introspection_cpp::AprilTagPixelArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, avig_msg, msg, AprilTagPixelArray)() {
  return &::avig_msg::msg::rosidl_typesupport_introspection_cpp::AprilTagPixelArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
