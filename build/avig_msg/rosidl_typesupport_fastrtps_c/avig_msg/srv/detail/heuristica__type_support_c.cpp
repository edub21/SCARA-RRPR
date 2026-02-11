// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from avig_msg:srv/Heuristica.idl
// generated code does not contain a copyright notice
#include "avig_msg/srv/detail/heuristica__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "avig_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "avig_msg/srv/detail/heuristica__struct.h"
#include "avig_msg/srv/detail/heuristica__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "avig_msg/msg/detail/april_tag_pixel_array__functions.h"  // tags_in

// forward declare type support functions
size_t get_serialized_size_avig_msg__msg__AprilTagPixelArray(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_avig_msg__msg__AprilTagPixelArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, avig_msg, msg, AprilTagPixelArray)();


using _Heuristica_Request__ros_msg_type = avig_msg__srv__Heuristica_Request;

static bool _Heuristica_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Heuristica_Request__ros_msg_type * ros_message = static_cast<const _Heuristica_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: tags_in
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, avig_msg, msg, AprilTagPixelArray
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tags_in, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Heuristica_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Heuristica_Request__ros_msg_type * ros_message = static_cast<_Heuristica_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: tags_in
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, avig_msg, msg, AprilTagPixelArray
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tags_in))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_avig_msg
size_t get_serialized_size_avig_msg__srv__Heuristica_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Heuristica_Request__ros_msg_type * ros_message = static_cast<const _Heuristica_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name tags_in

  current_alignment += get_serialized_size_avig_msg__msg__AprilTagPixelArray(
    &(ros_message->tags_in), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Heuristica_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_avig_msg__srv__Heuristica_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_avig_msg
size_t max_serialized_size_avig_msg__srv__Heuristica_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: tags_in
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_avig_msg__msg__AprilTagPixelArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = avig_msg__srv__Heuristica_Request;
    is_plain =
      (
      offsetof(DataType, tags_in) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Heuristica_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_avig_msg__srv__Heuristica_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Heuristica_Request = {
  "avig_msg::srv",
  "Heuristica_Request",
  _Heuristica_Request__cdr_serialize,
  _Heuristica_Request__cdr_deserialize,
  _Heuristica_Request__get_serialized_size,
  _Heuristica_Request__max_serialized_size
};

static rosidl_message_type_support_t _Heuristica_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Heuristica_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, avig_msg, srv, Heuristica_Request)() {
  return &_Heuristica_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "avig_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "avig_msg/srv/detail/heuristica__struct.h"
// already included above
// #include "avig_msg/srv/detail/heuristica__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "avig_msg/msg/detail/april_tag_pixel__functions.h"  // tag_out

// forward declare type support functions
size_t get_serialized_size_avig_msg__msg__AprilTagPixel(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_avig_msg__msg__AprilTagPixel(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, avig_msg, msg, AprilTagPixel)();


using _Heuristica_Response__ros_msg_type = avig_msg__srv__Heuristica_Response;

static bool _Heuristica_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Heuristica_Response__ros_msg_type * ros_message = static_cast<const _Heuristica_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: tag_out
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, avig_msg, msg, AprilTagPixel
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tag_out, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Heuristica_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Heuristica_Response__ros_msg_type * ros_message = static_cast<_Heuristica_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: tag_out
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, avig_msg, msg, AprilTagPixel
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tag_out))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_avig_msg
size_t get_serialized_size_avig_msg__srv__Heuristica_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Heuristica_Response__ros_msg_type * ros_message = static_cast<const _Heuristica_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name tag_out

  current_alignment += get_serialized_size_avig_msg__msg__AprilTagPixel(
    &(ros_message->tag_out), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Heuristica_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_avig_msg__srv__Heuristica_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_avig_msg
size_t max_serialized_size_avig_msg__srv__Heuristica_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: tag_out
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_avig_msg__msg__AprilTagPixel(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = avig_msg__srv__Heuristica_Response;
    is_plain =
      (
      offsetof(DataType, tag_out) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Heuristica_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_avig_msg__srv__Heuristica_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Heuristica_Response = {
  "avig_msg::srv",
  "Heuristica_Response",
  _Heuristica_Response__cdr_serialize,
  _Heuristica_Response__cdr_deserialize,
  _Heuristica_Response__get_serialized_size,
  _Heuristica_Response__max_serialized_size
};

static rosidl_message_type_support_t _Heuristica_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Heuristica_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, avig_msg, srv, Heuristica_Response)() {
  return &_Heuristica_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "avig_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "avig_msg/srv/heuristica.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Heuristica__callbacks = {
  "avig_msg::srv",
  "Heuristica",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, avig_msg, srv, Heuristica_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, avig_msg, srv, Heuristica_Response)(),
};

static rosidl_service_type_support_t Heuristica__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Heuristica__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, avig_msg, srv, Heuristica)() {
  return &Heuristica__handle;
}

#if defined(__cplusplus)
}
#endif
