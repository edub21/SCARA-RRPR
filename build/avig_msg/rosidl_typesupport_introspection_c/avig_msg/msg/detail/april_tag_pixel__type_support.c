// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from avig_msg:msg/AprilTagPixel.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "avig_msg/msg/detail/april_tag_pixel__rosidl_typesupport_introspection_c.h"
#include "avig_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "avig_msg/msg/detail/april_tag_pixel__functions.h"
#include "avig_msg/msg/detail/april_tag_pixel__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  avig_msg__msg__AprilTagPixel__init(message_memory);
}

void avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_fini_function(void * message_memory)
{
  avig_msg__msg__AprilTagPixel__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_message_member_array[6] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(avig_msg__msg__AprilTagPixel, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "posx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(avig_msg__msg__AprilTagPixel, posx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "posy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(avig_msg__msg__AprilTagPixel, posy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "orden",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(avig_msg__msg__AprilTagPixel, orden),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dist",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(avig_msg__msg__AprilTagPixel, dist),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "orient",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(avig_msg__msg__AprilTagPixel, orient),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_message_members = {
  "avig_msg__msg",  // message namespace
  "AprilTagPixel",  // message name
  6,  // number of fields
  sizeof(avig_msg__msg__AprilTagPixel),
  avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_message_member_array,  // message members
  avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_init_function,  // function to initialize message memory (memory has to be allocated)
  avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_message_type_support_handle = {
  0,
  &avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_avig_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, avig_msg, msg, AprilTagPixel)() {
  if (!avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_message_type_support_handle.typesupport_identifier) {
    avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &avig_msg__msg__AprilTagPixel__rosidl_typesupport_introspection_c__AprilTagPixel_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
