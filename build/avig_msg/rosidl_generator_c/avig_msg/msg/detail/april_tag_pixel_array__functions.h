// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from avig_msg:msg/AprilTagPixelArray.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__FUNCTIONS_H_
#define AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "avig_msg/msg/rosidl_generator_c__visibility_control.h"

#include "avig_msg/msg/detail/april_tag_pixel_array__struct.h"

/// Initialize msg/AprilTagPixelArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * avig_msg__msg__AprilTagPixelArray
 * )) before or use
 * avig_msg__msg__AprilTagPixelArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__msg__AprilTagPixelArray__init(avig_msg__msg__AprilTagPixelArray * msg);

/// Finalize msg/AprilTagPixelArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__msg__AprilTagPixelArray__fini(avig_msg__msg__AprilTagPixelArray * msg);

/// Create msg/AprilTagPixelArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * avig_msg__msg__AprilTagPixelArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__msg__AprilTagPixelArray *
avig_msg__msg__AprilTagPixelArray__create();

/// Destroy msg/AprilTagPixelArray message.
/**
 * It calls
 * avig_msg__msg__AprilTagPixelArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__msg__AprilTagPixelArray__destroy(avig_msg__msg__AprilTagPixelArray * msg);

/// Check for msg/AprilTagPixelArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__msg__AprilTagPixelArray__are_equal(const avig_msg__msg__AprilTagPixelArray * lhs, const avig_msg__msg__AprilTagPixelArray * rhs);

/// Copy a msg/AprilTagPixelArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__msg__AprilTagPixelArray__copy(
  const avig_msg__msg__AprilTagPixelArray * input,
  avig_msg__msg__AprilTagPixelArray * output);

/// Initialize array of msg/AprilTagPixelArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * avig_msg__msg__AprilTagPixelArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__msg__AprilTagPixelArray__Sequence__init(avig_msg__msg__AprilTagPixelArray__Sequence * array, size_t size);

/// Finalize array of msg/AprilTagPixelArray messages.
/**
 * It calls
 * avig_msg__msg__AprilTagPixelArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__msg__AprilTagPixelArray__Sequence__fini(avig_msg__msg__AprilTagPixelArray__Sequence * array);

/// Create array of msg/AprilTagPixelArray messages.
/**
 * It allocates the memory for the array and calls
 * avig_msg__msg__AprilTagPixelArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__msg__AprilTagPixelArray__Sequence *
avig_msg__msg__AprilTagPixelArray__Sequence__create(size_t size);

/// Destroy array of msg/AprilTagPixelArray messages.
/**
 * It calls
 * avig_msg__msg__AprilTagPixelArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__msg__AprilTagPixelArray__Sequence__destroy(avig_msg__msg__AprilTagPixelArray__Sequence * array);

/// Check for msg/AprilTagPixelArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__msg__AprilTagPixelArray__Sequence__are_equal(const avig_msg__msg__AprilTagPixelArray__Sequence * lhs, const avig_msg__msg__AprilTagPixelArray__Sequence * rhs);

/// Copy an array of msg/AprilTagPixelArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__msg__AprilTagPixelArray__Sequence__copy(
  const avig_msg__msg__AprilTagPixelArray__Sequence * input,
  avig_msg__msg__AprilTagPixelArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__FUNCTIONS_H_
