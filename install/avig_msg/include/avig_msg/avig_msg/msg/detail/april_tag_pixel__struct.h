// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from avig_msg:msg/AprilTagPixel.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL__STRUCT_H_
#define AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AprilTagPixel in the package avig_msg.
typedef struct avig_msg__msg__AprilTagPixel
{
  int32_t id;
  float posx;
  float posy;
  int32_t orden;
  float dist;
  float orient;
} avig_msg__msg__AprilTagPixel;

// Struct for a sequence of avig_msg__msg__AprilTagPixel.
typedef struct avig_msg__msg__AprilTagPixel__Sequence
{
  avig_msg__msg__AprilTagPixel * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__msg__AprilTagPixel__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL__STRUCT_H_
