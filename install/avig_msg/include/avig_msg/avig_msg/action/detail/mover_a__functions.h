// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from avig_msg:action/MoverA.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__ACTION__DETAIL__MOVER_A__FUNCTIONS_H_
#define AVIG_MSG__ACTION__DETAIL__MOVER_A__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "avig_msg/msg/rosidl_generator_c__visibility_control.h"

#include "avig_msg/action/detail/mover_a__struct.h"

/// Initialize action/MoverA message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * avig_msg__action__MoverA_Goal
 * )) before or use
 * avig_msg__action__MoverA_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Goal__init(avig_msg__action__MoverA_Goal * msg);

/// Finalize action/MoverA message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Goal__fini(avig_msg__action__MoverA_Goal * msg);

/// Create action/MoverA message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * avig_msg__action__MoverA_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_Goal *
avig_msg__action__MoverA_Goal__create();

/// Destroy action/MoverA message.
/**
 * It calls
 * avig_msg__action__MoverA_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Goal__destroy(avig_msg__action__MoverA_Goal * msg);

/// Check for action/MoverA message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Goal__are_equal(const avig_msg__action__MoverA_Goal * lhs, const avig_msg__action__MoverA_Goal * rhs);

/// Copy a action/MoverA message.
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
avig_msg__action__MoverA_Goal__copy(
  const avig_msg__action__MoverA_Goal * input,
  avig_msg__action__MoverA_Goal * output);

/// Initialize array of action/MoverA messages.
/**
 * It allocates the memory for the number of elements and calls
 * avig_msg__action__MoverA_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Goal__Sequence__init(avig_msg__action__MoverA_Goal__Sequence * array, size_t size);

/// Finalize array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Goal__Sequence__fini(avig_msg__action__MoverA_Goal__Sequence * array);

/// Create array of action/MoverA messages.
/**
 * It allocates the memory for the array and calls
 * avig_msg__action__MoverA_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_Goal__Sequence *
avig_msg__action__MoverA_Goal__Sequence__create(size_t size);

/// Destroy array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Goal__Sequence__destroy(avig_msg__action__MoverA_Goal__Sequence * array);

/// Check for action/MoverA message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Goal__Sequence__are_equal(const avig_msg__action__MoverA_Goal__Sequence * lhs, const avig_msg__action__MoverA_Goal__Sequence * rhs);

/// Copy an array of action/MoverA messages.
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
avig_msg__action__MoverA_Goal__Sequence__copy(
  const avig_msg__action__MoverA_Goal__Sequence * input,
  avig_msg__action__MoverA_Goal__Sequence * output);

/// Initialize action/MoverA message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * avig_msg__action__MoverA_Result
 * )) before or use
 * avig_msg__action__MoverA_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Result__init(avig_msg__action__MoverA_Result * msg);

/// Finalize action/MoverA message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Result__fini(avig_msg__action__MoverA_Result * msg);

/// Create action/MoverA message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * avig_msg__action__MoverA_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_Result *
avig_msg__action__MoverA_Result__create();

/// Destroy action/MoverA message.
/**
 * It calls
 * avig_msg__action__MoverA_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Result__destroy(avig_msg__action__MoverA_Result * msg);

/// Check for action/MoverA message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Result__are_equal(const avig_msg__action__MoverA_Result * lhs, const avig_msg__action__MoverA_Result * rhs);

/// Copy a action/MoverA message.
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
avig_msg__action__MoverA_Result__copy(
  const avig_msg__action__MoverA_Result * input,
  avig_msg__action__MoverA_Result * output);

/// Initialize array of action/MoverA messages.
/**
 * It allocates the memory for the number of elements and calls
 * avig_msg__action__MoverA_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Result__Sequence__init(avig_msg__action__MoverA_Result__Sequence * array, size_t size);

/// Finalize array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Result__Sequence__fini(avig_msg__action__MoverA_Result__Sequence * array);

/// Create array of action/MoverA messages.
/**
 * It allocates the memory for the array and calls
 * avig_msg__action__MoverA_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_Result__Sequence *
avig_msg__action__MoverA_Result__Sequence__create(size_t size);

/// Destroy array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Result__Sequence__destroy(avig_msg__action__MoverA_Result__Sequence * array);

/// Check for action/MoverA message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Result__Sequence__are_equal(const avig_msg__action__MoverA_Result__Sequence * lhs, const avig_msg__action__MoverA_Result__Sequence * rhs);

/// Copy an array of action/MoverA messages.
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
avig_msg__action__MoverA_Result__Sequence__copy(
  const avig_msg__action__MoverA_Result__Sequence * input,
  avig_msg__action__MoverA_Result__Sequence * output);

/// Initialize action/MoverA message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * avig_msg__action__MoverA_Feedback
 * )) before or use
 * avig_msg__action__MoverA_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Feedback__init(avig_msg__action__MoverA_Feedback * msg);

/// Finalize action/MoverA message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Feedback__fini(avig_msg__action__MoverA_Feedback * msg);

/// Create action/MoverA message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * avig_msg__action__MoverA_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_Feedback *
avig_msg__action__MoverA_Feedback__create();

/// Destroy action/MoverA message.
/**
 * It calls
 * avig_msg__action__MoverA_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Feedback__destroy(avig_msg__action__MoverA_Feedback * msg);

/// Check for action/MoverA message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Feedback__are_equal(const avig_msg__action__MoverA_Feedback * lhs, const avig_msg__action__MoverA_Feedback * rhs);

/// Copy a action/MoverA message.
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
avig_msg__action__MoverA_Feedback__copy(
  const avig_msg__action__MoverA_Feedback * input,
  avig_msg__action__MoverA_Feedback * output);

/// Initialize array of action/MoverA messages.
/**
 * It allocates the memory for the number of elements and calls
 * avig_msg__action__MoverA_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Feedback__Sequence__init(avig_msg__action__MoverA_Feedback__Sequence * array, size_t size);

/// Finalize array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Feedback__Sequence__fini(avig_msg__action__MoverA_Feedback__Sequence * array);

/// Create array of action/MoverA messages.
/**
 * It allocates the memory for the array and calls
 * avig_msg__action__MoverA_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_Feedback__Sequence *
avig_msg__action__MoverA_Feedback__Sequence__create(size_t size);

/// Destroy array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_Feedback__Sequence__destroy(avig_msg__action__MoverA_Feedback__Sequence * array);

/// Check for action/MoverA message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_Feedback__Sequence__are_equal(const avig_msg__action__MoverA_Feedback__Sequence * lhs, const avig_msg__action__MoverA_Feedback__Sequence * rhs);

/// Copy an array of action/MoverA messages.
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
avig_msg__action__MoverA_Feedback__Sequence__copy(
  const avig_msg__action__MoverA_Feedback__Sequence * input,
  avig_msg__action__MoverA_Feedback__Sequence * output);

/// Initialize action/MoverA message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * avig_msg__action__MoverA_SendGoal_Request
 * )) before or use
 * avig_msg__action__MoverA_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_SendGoal_Request__init(avig_msg__action__MoverA_SendGoal_Request * msg);

/// Finalize action/MoverA message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_SendGoal_Request__fini(avig_msg__action__MoverA_SendGoal_Request * msg);

/// Create action/MoverA message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * avig_msg__action__MoverA_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_SendGoal_Request *
avig_msg__action__MoverA_SendGoal_Request__create();

/// Destroy action/MoverA message.
/**
 * It calls
 * avig_msg__action__MoverA_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_SendGoal_Request__destroy(avig_msg__action__MoverA_SendGoal_Request * msg);

/// Check for action/MoverA message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_SendGoal_Request__are_equal(const avig_msg__action__MoverA_SendGoal_Request * lhs, const avig_msg__action__MoverA_SendGoal_Request * rhs);

/// Copy a action/MoverA message.
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
avig_msg__action__MoverA_SendGoal_Request__copy(
  const avig_msg__action__MoverA_SendGoal_Request * input,
  avig_msg__action__MoverA_SendGoal_Request * output);

/// Initialize array of action/MoverA messages.
/**
 * It allocates the memory for the number of elements and calls
 * avig_msg__action__MoverA_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_SendGoal_Request__Sequence__init(avig_msg__action__MoverA_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_SendGoal_Request__Sequence__fini(avig_msg__action__MoverA_SendGoal_Request__Sequence * array);

/// Create array of action/MoverA messages.
/**
 * It allocates the memory for the array and calls
 * avig_msg__action__MoverA_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_SendGoal_Request__Sequence *
avig_msg__action__MoverA_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_SendGoal_Request__Sequence__destroy(avig_msg__action__MoverA_SendGoal_Request__Sequence * array);

/// Check for action/MoverA message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_SendGoal_Request__Sequence__are_equal(const avig_msg__action__MoverA_SendGoal_Request__Sequence * lhs, const avig_msg__action__MoverA_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/MoverA messages.
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
avig_msg__action__MoverA_SendGoal_Request__Sequence__copy(
  const avig_msg__action__MoverA_SendGoal_Request__Sequence * input,
  avig_msg__action__MoverA_SendGoal_Request__Sequence * output);

/// Initialize action/MoverA message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * avig_msg__action__MoverA_SendGoal_Response
 * )) before or use
 * avig_msg__action__MoverA_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_SendGoal_Response__init(avig_msg__action__MoverA_SendGoal_Response * msg);

/// Finalize action/MoverA message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_SendGoal_Response__fini(avig_msg__action__MoverA_SendGoal_Response * msg);

/// Create action/MoverA message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * avig_msg__action__MoverA_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_SendGoal_Response *
avig_msg__action__MoverA_SendGoal_Response__create();

/// Destroy action/MoverA message.
/**
 * It calls
 * avig_msg__action__MoverA_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_SendGoal_Response__destroy(avig_msg__action__MoverA_SendGoal_Response * msg);

/// Check for action/MoverA message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_SendGoal_Response__are_equal(const avig_msg__action__MoverA_SendGoal_Response * lhs, const avig_msg__action__MoverA_SendGoal_Response * rhs);

/// Copy a action/MoverA message.
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
avig_msg__action__MoverA_SendGoal_Response__copy(
  const avig_msg__action__MoverA_SendGoal_Response * input,
  avig_msg__action__MoverA_SendGoal_Response * output);

/// Initialize array of action/MoverA messages.
/**
 * It allocates the memory for the number of elements and calls
 * avig_msg__action__MoverA_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_SendGoal_Response__Sequence__init(avig_msg__action__MoverA_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_SendGoal_Response__Sequence__fini(avig_msg__action__MoverA_SendGoal_Response__Sequence * array);

/// Create array of action/MoverA messages.
/**
 * It allocates the memory for the array and calls
 * avig_msg__action__MoverA_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_SendGoal_Response__Sequence *
avig_msg__action__MoverA_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_SendGoal_Response__Sequence__destroy(avig_msg__action__MoverA_SendGoal_Response__Sequence * array);

/// Check for action/MoverA message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_SendGoal_Response__Sequence__are_equal(const avig_msg__action__MoverA_SendGoal_Response__Sequence * lhs, const avig_msg__action__MoverA_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/MoverA messages.
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
avig_msg__action__MoverA_SendGoal_Response__Sequence__copy(
  const avig_msg__action__MoverA_SendGoal_Response__Sequence * input,
  avig_msg__action__MoverA_SendGoal_Response__Sequence * output);

/// Initialize action/MoverA message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * avig_msg__action__MoverA_GetResult_Request
 * )) before or use
 * avig_msg__action__MoverA_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_GetResult_Request__init(avig_msg__action__MoverA_GetResult_Request * msg);

/// Finalize action/MoverA message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_GetResult_Request__fini(avig_msg__action__MoverA_GetResult_Request * msg);

/// Create action/MoverA message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * avig_msg__action__MoverA_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_GetResult_Request *
avig_msg__action__MoverA_GetResult_Request__create();

/// Destroy action/MoverA message.
/**
 * It calls
 * avig_msg__action__MoverA_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_GetResult_Request__destroy(avig_msg__action__MoverA_GetResult_Request * msg);

/// Check for action/MoverA message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_GetResult_Request__are_equal(const avig_msg__action__MoverA_GetResult_Request * lhs, const avig_msg__action__MoverA_GetResult_Request * rhs);

/// Copy a action/MoverA message.
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
avig_msg__action__MoverA_GetResult_Request__copy(
  const avig_msg__action__MoverA_GetResult_Request * input,
  avig_msg__action__MoverA_GetResult_Request * output);

/// Initialize array of action/MoverA messages.
/**
 * It allocates the memory for the number of elements and calls
 * avig_msg__action__MoverA_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_GetResult_Request__Sequence__init(avig_msg__action__MoverA_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_GetResult_Request__Sequence__fini(avig_msg__action__MoverA_GetResult_Request__Sequence * array);

/// Create array of action/MoverA messages.
/**
 * It allocates the memory for the array and calls
 * avig_msg__action__MoverA_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_GetResult_Request__Sequence *
avig_msg__action__MoverA_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_GetResult_Request__Sequence__destroy(avig_msg__action__MoverA_GetResult_Request__Sequence * array);

/// Check for action/MoverA message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_GetResult_Request__Sequence__are_equal(const avig_msg__action__MoverA_GetResult_Request__Sequence * lhs, const avig_msg__action__MoverA_GetResult_Request__Sequence * rhs);

/// Copy an array of action/MoverA messages.
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
avig_msg__action__MoverA_GetResult_Request__Sequence__copy(
  const avig_msg__action__MoverA_GetResult_Request__Sequence * input,
  avig_msg__action__MoverA_GetResult_Request__Sequence * output);

/// Initialize action/MoverA message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * avig_msg__action__MoverA_GetResult_Response
 * )) before or use
 * avig_msg__action__MoverA_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_GetResult_Response__init(avig_msg__action__MoverA_GetResult_Response * msg);

/// Finalize action/MoverA message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_GetResult_Response__fini(avig_msg__action__MoverA_GetResult_Response * msg);

/// Create action/MoverA message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * avig_msg__action__MoverA_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_GetResult_Response *
avig_msg__action__MoverA_GetResult_Response__create();

/// Destroy action/MoverA message.
/**
 * It calls
 * avig_msg__action__MoverA_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_GetResult_Response__destroy(avig_msg__action__MoverA_GetResult_Response * msg);

/// Check for action/MoverA message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_GetResult_Response__are_equal(const avig_msg__action__MoverA_GetResult_Response * lhs, const avig_msg__action__MoverA_GetResult_Response * rhs);

/// Copy a action/MoverA message.
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
avig_msg__action__MoverA_GetResult_Response__copy(
  const avig_msg__action__MoverA_GetResult_Response * input,
  avig_msg__action__MoverA_GetResult_Response * output);

/// Initialize array of action/MoverA messages.
/**
 * It allocates the memory for the number of elements and calls
 * avig_msg__action__MoverA_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_GetResult_Response__Sequence__init(avig_msg__action__MoverA_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_GetResult_Response__Sequence__fini(avig_msg__action__MoverA_GetResult_Response__Sequence * array);

/// Create array of action/MoverA messages.
/**
 * It allocates the memory for the array and calls
 * avig_msg__action__MoverA_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_GetResult_Response__Sequence *
avig_msg__action__MoverA_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_GetResult_Response__Sequence__destroy(avig_msg__action__MoverA_GetResult_Response__Sequence * array);

/// Check for action/MoverA message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_GetResult_Response__Sequence__are_equal(const avig_msg__action__MoverA_GetResult_Response__Sequence * lhs, const avig_msg__action__MoverA_GetResult_Response__Sequence * rhs);

/// Copy an array of action/MoverA messages.
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
avig_msg__action__MoverA_GetResult_Response__Sequence__copy(
  const avig_msg__action__MoverA_GetResult_Response__Sequence * input,
  avig_msg__action__MoverA_GetResult_Response__Sequence * output);

/// Initialize action/MoverA message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * avig_msg__action__MoverA_FeedbackMessage
 * )) before or use
 * avig_msg__action__MoverA_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_FeedbackMessage__init(avig_msg__action__MoverA_FeedbackMessage * msg);

/// Finalize action/MoverA message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_FeedbackMessage__fini(avig_msg__action__MoverA_FeedbackMessage * msg);

/// Create action/MoverA message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * avig_msg__action__MoverA_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_FeedbackMessage *
avig_msg__action__MoverA_FeedbackMessage__create();

/// Destroy action/MoverA message.
/**
 * It calls
 * avig_msg__action__MoverA_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_FeedbackMessage__destroy(avig_msg__action__MoverA_FeedbackMessage * msg);

/// Check for action/MoverA message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_FeedbackMessage__are_equal(const avig_msg__action__MoverA_FeedbackMessage * lhs, const avig_msg__action__MoverA_FeedbackMessage * rhs);

/// Copy a action/MoverA message.
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
avig_msg__action__MoverA_FeedbackMessage__copy(
  const avig_msg__action__MoverA_FeedbackMessage * input,
  avig_msg__action__MoverA_FeedbackMessage * output);

/// Initialize array of action/MoverA messages.
/**
 * It allocates the memory for the number of elements and calls
 * avig_msg__action__MoverA_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_FeedbackMessage__Sequence__init(avig_msg__action__MoverA_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_FeedbackMessage__Sequence__fini(avig_msg__action__MoverA_FeedbackMessage__Sequence * array);

/// Create array of action/MoverA messages.
/**
 * It allocates the memory for the array and calls
 * avig_msg__action__MoverA_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
avig_msg__action__MoverA_FeedbackMessage__Sequence *
avig_msg__action__MoverA_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/MoverA messages.
/**
 * It calls
 * avig_msg__action__MoverA_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
void
avig_msg__action__MoverA_FeedbackMessage__Sequence__destroy(avig_msg__action__MoverA_FeedbackMessage__Sequence * array);

/// Check for action/MoverA message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_avig_msg
bool
avig_msg__action__MoverA_FeedbackMessage__Sequence__are_equal(const avig_msg__action__MoverA_FeedbackMessage__Sequence * lhs, const avig_msg__action__MoverA_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/MoverA messages.
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
avig_msg__action__MoverA_FeedbackMessage__Sequence__copy(
  const avig_msg__action__MoverA_FeedbackMessage__Sequence * input,
  avig_msg__action__MoverA_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AVIG_MSG__ACTION__DETAIL__MOVER_A__FUNCTIONS_H_
