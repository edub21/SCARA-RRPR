// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from avig_msg:srv/Heuristica.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__SRV__DETAIL__HEURISTICA__STRUCT_H_
#define AVIG_MSG__SRV__DETAIL__HEURISTICA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tags_in'
#include "avig_msg/msg/detail/april_tag_pixel_array__struct.h"

/// Struct defined in srv/Heuristica in the package avig_msg.
typedef struct avig_msg__srv__Heuristica_Request
{
  avig_msg__msg__AprilTagPixelArray tags_in;
} avig_msg__srv__Heuristica_Request;

// Struct for a sequence of avig_msg__srv__Heuristica_Request.
typedef struct avig_msg__srv__Heuristica_Request__Sequence
{
  avig_msg__srv__Heuristica_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__srv__Heuristica_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'tag_out'
#include "avig_msg/msg/detail/april_tag_pixel__struct.h"

/// Struct defined in srv/Heuristica in the package avig_msg.
typedef struct avig_msg__srv__Heuristica_Response
{
  avig_msg__msg__AprilTagPixel tag_out;
} avig_msg__srv__Heuristica_Response;

// Struct for a sequence of avig_msg__srv__Heuristica_Response.
typedef struct avig_msg__srv__Heuristica_Response__Sequence
{
  avig_msg__srv__Heuristica_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__srv__Heuristica_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AVIG_MSG__SRV__DETAIL__HEURISTICA__STRUCT_H_
