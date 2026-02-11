// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from avig_msg:msg/ObjDetect.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__MSG__DETAIL__OBJ_DETECT__STRUCT_H_
#define AVIG_MSG__MSG__DETAIL__OBJ_DETECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ObjDetect in the package avig_msg.
typedef struct avig_msg__msg__ObjDetect
{
  int32_t id;
  float posx;
  float posy;
  int32_t orden;
  float dist;
  float orient;
} avig_msg__msg__ObjDetect;

// Struct for a sequence of avig_msg__msg__ObjDetect.
typedef struct avig_msg__msg__ObjDetect__Sequence
{
  avig_msg__msg__ObjDetect * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__msg__ObjDetect__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AVIG_MSG__MSG__DETAIL__OBJ_DETECT__STRUCT_H_
