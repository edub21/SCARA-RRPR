// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from avig_msg:msg/AprilTagPixelArray.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__STRUCT_H_
#define AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tags'
#include "avig_msg/msg/detail/april_tag_pixel__struct.h"

/// Struct defined in msg/AprilTagPixelArray in the package avig_msg.
typedef struct avig_msg__msg__AprilTagPixelArray
{
  avig_msg__msg__AprilTagPixel__Sequence tags;
} avig_msg__msg__AprilTagPixelArray;

// Struct for a sequence of avig_msg__msg__AprilTagPixelArray.
typedef struct avig_msg__msg__AprilTagPixelArray__Sequence
{
  avig_msg__msg__AprilTagPixelArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__msg__AprilTagPixelArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__STRUCT_H_
