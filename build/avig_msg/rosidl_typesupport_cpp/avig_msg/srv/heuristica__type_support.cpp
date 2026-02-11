// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from avig_msg:srv/Heuristica.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "avig_msg/srv/detail/heuristica__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace avig_msg
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Heuristica_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Heuristica_Request_type_support_ids_t;

static const _Heuristica_Request_type_support_ids_t _Heuristica_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Heuristica_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Heuristica_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Heuristica_Request_type_support_symbol_names_t _Heuristica_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, avig_msg, srv, Heuristica_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, avig_msg, srv, Heuristica_Request)),
  }
};

typedef struct _Heuristica_Request_type_support_data_t
{
  void * data[2];
} _Heuristica_Request_type_support_data_t;

static _Heuristica_Request_type_support_data_t _Heuristica_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Heuristica_Request_message_typesupport_map = {
  2,
  "avig_msg",
  &_Heuristica_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Heuristica_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Heuristica_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Heuristica_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Heuristica_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace avig_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<avig_msg::srv::Heuristica_Request>()
{
  return &::avig_msg::srv::rosidl_typesupport_cpp::Heuristica_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, avig_msg, srv, Heuristica_Request)() {
  return get_message_type_support_handle<avig_msg::srv::Heuristica_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "avig_msg/srv/detail/heuristica__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace avig_msg
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Heuristica_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Heuristica_Response_type_support_ids_t;

static const _Heuristica_Response_type_support_ids_t _Heuristica_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Heuristica_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Heuristica_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Heuristica_Response_type_support_symbol_names_t _Heuristica_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, avig_msg, srv, Heuristica_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, avig_msg, srv, Heuristica_Response)),
  }
};

typedef struct _Heuristica_Response_type_support_data_t
{
  void * data[2];
} _Heuristica_Response_type_support_data_t;

static _Heuristica_Response_type_support_data_t _Heuristica_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Heuristica_Response_message_typesupport_map = {
  2,
  "avig_msg",
  &_Heuristica_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Heuristica_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Heuristica_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Heuristica_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Heuristica_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace avig_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<avig_msg::srv::Heuristica_Response>()
{
  return &::avig_msg::srv::rosidl_typesupport_cpp::Heuristica_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, avig_msg, srv, Heuristica_Response)() {
  return get_message_type_support_handle<avig_msg::srv::Heuristica_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "avig_msg/srv/detail/heuristica__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace avig_msg
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Heuristica_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Heuristica_type_support_ids_t;

static const _Heuristica_type_support_ids_t _Heuristica_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Heuristica_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Heuristica_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Heuristica_type_support_symbol_names_t _Heuristica_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, avig_msg, srv, Heuristica)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, avig_msg, srv, Heuristica)),
  }
};

typedef struct _Heuristica_type_support_data_t
{
  void * data[2];
} _Heuristica_type_support_data_t;

static _Heuristica_type_support_data_t _Heuristica_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Heuristica_service_typesupport_map = {
  2,
  "avig_msg",
  &_Heuristica_service_typesupport_ids.typesupport_identifier[0],
  &_Heuristica_service_typesupport_symbol_names.symbol_name[0],
  &_Heuristica_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Heuristica_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Heuristica_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace avig_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<avig_msg::srv::Heuristica>()
{
  return &::avig_msg::srv::rosidl_typesupport_cpp::Heuristica_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, avig_msg, srv, Heuristica)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<avig_msg::srv::Heuristica>();
}

#ifdef __cplusplus
}
#endif
