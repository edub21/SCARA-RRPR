// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from avig_msg:srv/Heuristica.idl
// generated code does not contain a copyright notice
#include "avig_msg/srv/detail/heuristica__rosidl_typesupport_fastrtps_cpp.hpp"
#include "avig_msg/srv/detail/heuristica__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace avig_msg
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const avig_msg::msg::AprilTagPixelArray &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  avig_msg::msg::AprilTagPixelArray &);
size_t get_serialized_size(
  const avig_msg::msg::AprilTagPixelArray &,
  size_t current_alignment);
size_t
max_serialized_size_AprilTagPixelArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace avig_msg


namespace avig_msg
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
cdr_serialize(
  const avig_msg::srv::Heuristica_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: tags_in
  avig_msg::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.tags_in,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  avig_msg::srv::Heuristica_Request & ros_message)
{
  // Member: tags_in
  avig_msg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.tags_in);

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
get_serialized_size(
  const avig_msg::srv::Heuristica_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: tags_in

  current_alignment +=
    avig_msg::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.tags_in, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
max_serialized_size_Heuristica_Request(
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


  // Member: tags_in
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        avig_msg::msg::typesupport_fastrtps_cpp::max_serialized_size_AprilTagPixelArray(
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
    using DataType = avig_msg::srv::Heuristica_Request;
    is_plain =
      (
      offsetof(DataType, tags_in) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Heuristica_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const avig_msg::srv::Heuristica_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Heuristica_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<avig_msg::srv::Heuristica_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Heuristica_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const avig_msg::srv::Heuristica_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Heuristica_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Heuristica_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Heuristica_Request__callbacks = {
  "avig_msg::srv",
  "Heuristica_Request",
  _Heuristica_Request__cdr_serialize,
  _Heuristica_Request__cdr_deserialize,
  _Heuristica_Request__get_serialized_size,
  _Heuristica_Request__max_serialized_size
};

static rosidl_message_type_support_t _Heuristica_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Heuristica_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace avig_msg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_avig_msg
const rosidl_message_type_support_t *
get_message_type_support_handle<avig_msg::srv::Heuristica_Request>()
{
  return &avig_msg::srv::typesupport_fastrtps_cpp::_Heuristica_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, avig_msg, srv, Heuristica_Request)() {
  return &avig_msg::srv::typesupport_fastrtps_cpp::_Heuristica_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace avig_msg
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const avig_msg::msg::AprilTagPixel &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  avig_msg::msg::AprilTagPixel &);
size_t get_serialized_size(
  const avig_msg::msg::AprilTagPixel &,
  size_t current_alignment);
size_t
max_serialized_size_AprilTagPixel(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace avig_msg


namespace avig_msg
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
cdr_serialize(
  const avig_msg::srv::Heuristica_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: tag_out
  avig_msg::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.tag_out,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  avig_msg::srv::Heuristica_Response & ros_message)
{
  // Member: tag_out
  avig_msg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.tag_out);

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
get_serialized_size(
  const avig_msg::srv::Heuristica_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: tag_out

  current_alignment +=
    avig_msg::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.tag_out, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_avig_msg
max_serialized_size_Heuristica_Response(
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


  // Member: tag_out
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        avig_msg::msg::typesupport_fastrtps_cpp::max_serialized_size_AprilTagPixel(
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
    using DataType = avig_msg::srv::Heuristica_Response;
    is_plain =
      (
      offsetof(DataType, tag_out) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Heuristica_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const avig_msg::srv::Heuristica_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Heuristica_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<avig_msg::srv::Heuristica_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Heuristica_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const avig_msg::srv::Heuristica_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Heuristica_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Heuristica_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Heuristica_Response__callbacks = {
  "avig_msg::srv",
  "Heuristica_Response",
  _Heuristica_Response__cdr_serialize,
  _Heuristica_Response__cdr_deserialize,
  _Heuristica_Response__get_serialized_size,
  _Heuristica_Response__max_serialized_size
};

static rosidl_message_type_support_t _Heuristica_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Heuristica_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace avig_msg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_avig_msg
const rosidl_message_type_support_t *
get_message_type_support_handle<avig_msg::srv::Heuristica_Response>()
{
  return &avig_msg::srv::typesupport_fastrtps_cpp::_Heuristica_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, avig_msg, srv, Heuristica_Response)() {
  return &avig_msg::srv::typesupport_fastrtps_cpp::_Heuristica_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace avig_msg
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _Heuristica__callbacks = {
  "avig_msg::srv",
  "Heuristica",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, avig_msg, srv, Heuristica_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, avig_msg, srv, Heuristica_Response)(),
};

static rosidl_service_type_support_t _Heuristica__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Heuristica__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace avig_msg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_avig_msg
const rosidl_service_type_support_t *
get_service_type_support_handle<avig_msg::srv::Heuristica>()
{
  return &avig_msg::srv::typesupport_fastrtps_cpp::_Heuristica__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, avig_msg, srv, Heuristica)() {
  return &avig_msg::srv::typesupport_fastrtps_cpp::_Heuristica__handle;
}

#ifdef __cplusplus
}
#endif
