// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from avig_msg:msg/AprilTagPixelArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "avig_msg/msg/detail/april_tag_pixel_array__rosidl_typesupport_introspection_c.h"
#include "avig_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "avig_msg/msg/detail/april_tag_pixel_array__functions.h"
#include "avig_msg/msg/detail/april_tag_pixel_array__struct.h"


// Include directives for member types
// Member `tags`
#include "avig_msg/msg/april_tag_pixel.h"
// Member `tags`
#include "avig_msg/msg/detail/april_tag_pixel__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  avig_msg__msg__AprilTagPixelArray__init(message_memory);
}

void avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_fini_function(void * message_memory)
{
  avig_msg__msg__AprilTagPixelArray__fini(message_memory);
}

size_t avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__size_function__AprilTagPixelArray__tags(
  const void * untyped_member)
{
  const avig_msg__msg__AprilTagPixel__Sequence * member =
    (const avig_msg__msg__AprilTagPixel__Sequence *)(untyped_member);
  return member->size;
}

const void * avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__get_const_function__AprilTagPixelArray__tags(
  const void * untyped_member, size_t index)
{
  const avig_msg__msg__AprilTagPixel__Sequence * member =
    (const avig_msg__msg__AprilTagPixel__Sequence *)(untyped_member);
  return &member->data[index];
}

void * avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__get_function__AprilTagPixelArray__tags(
  void * untyped_member, size_t index)
{
  avig_msg__msg__AprilTagPixel__Sequence * member =
    (avig_msg__msg__AprilTagPixel__Sequence *)(untyped_member);
  return &member->data[index];
}

void avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__fetch_function__AprilTagPixelArray__tags(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const avig_msg__msg__AprilTagPixel * item =
    ((const avig_msg__msg__AprilTagPixel *)
    avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__get_const_function__AprilTagPixelArray__tags(untyped_member, index));
  avig_msg__msg__AprilTagPixel * value =
    (avig_msg__msg__AprilTagPixel *)(untyped_value);
  *value = *item;
}

void avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__assign_function__AprilTagPixelArray__tags(
  void * untyped_member, size_t index, const void * untyped_value)
{
  avig_msg__msg__AprilTagPixel * item =
    ((avig_msg__msg__AprilTagPixel *)
    avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__get_function__AprilTagPixelArray__tags(untyped_member, index));
  const avig_msg__msg__AprilTagPixel * value =
    (const avig_msg__msg__AprilTagPixel *)(untyped_value);
  *item = *value;
}

bool avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__resize_function__AprilTagPixelArray__tags(
  void * untyped_member, size_t size)
{
  avig_msg__msg__AprilTagPixel__Sequence * member =
    (avig_msg__msg__AprilTagPixel__Sequence *)(untyped_member);
  avig_msg__msg__AprilTagPixel__Sequence__fini(member);
  return avig_msg__msg__AprilTagPixel__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_message_member_array[1] = {
  {
    "tags",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(avig_msg__msg__AprilTagPixelArray, tags),  // bytes offset in struct
    NULL,  // default value
    avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__size_function__AprilTagPixelArray__tags,  // size() function pointer
    avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__get_const_function__AprilTagPixelArray__tags,  // get_const(index) function pointer
    avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__get_function__AprilTagPixelArray__tags,  // get(index) function pointer
    avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__fetch_function__AprilTagPixelArray__tags,  // fetch(index, &value) function pointer
    avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__assign_function__AprilTagPixelArray__tags,  // assign(index, value) function pointer
    avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__resize_function__AprilTagPixelArray__tags  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_message_members = {
  "avig_msg__msg",  // message namespace
  "AprilTagPixelArray",  // message name
  1,  // number of fields
  sizeof(avig_msg__msg__AprilTagPixelArray),
  avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_message_member_array,  // message members
  avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_init_function,  // function to initialize message memory (memory has to be allocated)
  avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_message_type_support_handle = {
  0,
  &avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_avig_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, avig_msg, msg, AprilTagPixelArray)() {
  avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, avig_msg, msg, AprilTagPixel)();
  if (!avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_message_type_support_handle.typesupport_identifier) {
    avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &avig_msg__msg__AprilTagPixelArray__rosidl_typesupport_introspection_c__AprilTagPixelArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
