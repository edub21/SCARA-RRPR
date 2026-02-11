// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from avig_msg:action/MoverA.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__ACTION__DETAIL__MOVER_A__STRUCT_H_
#define AVIG_MSG__ACTION__DETAIL__MOVER_A__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/MoverA in the package avig_msg.
typedef struct avig_msg__action__MoverA_Goal
{
  float x_actual;
  float y_actual;
  float x_meta;
  float y_meta;
} avig_msg__action__MoverA_Goal;

// Struct for a sequence of avig_msg__action__MoverA_Goal.
typedef struct avig_msg__action__MoverA_Goal__Sequence
{
  avig_msg__action__MoverA_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__action__MoverA_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/MoverA in the package avig_msg.
typedef struct avig_msg__action__MoverA_Result
{
  bool success;
} avig_msg__action__MoverA_Result;

// Struct for a sequence of avig_msg__action__MoverA_Result.
typedef struct avig_msg__action__MoverA_Result__Sequence
{
  avig_msg__action__MoverA_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__action__MoverA_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/MoverA in the package avig_msg.
typedef struct avig_msg__action__MoverA_Feedback
{
  float distancia_restante;
} avig_msg__action__MoverA_Feedback;

// Struct for a sequence of avig_msg__action__MoverA_Feedback.
typedef struct avig_msg__action__MoverA_Feedback__Sequence
{
  avig_msg__action__MoverA_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__action__MoverA_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "avig_msg/action/detail/mover_a__struct.h"

/// Struct defined in action/MoverA in the package avig_msg.
typedef struct avig_msg__action__MoverA_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  avig_msg__action__MoverA_Goal goal;
} avig_msg__action__MoverA_SendGoal_Request;

// Struct for a sequence of avig_msg__action__MoverA_SendGoal_Request.
typedef struct avig_msg__action__MoverA_SendGoal_Request__Sequence
{
  avig_msg__action__MoverA_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__action__MoverA_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/MoverA in the package avig_msg.
typedef struct avig_msg__action__MoverA_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} avig_msg__action__MoverA_SendGoal_Response;

// Struct for a sequence of avig_msg__action__MoverA_SendGoal_Response.
typedef struct avig_msg__action__MoverA_SendGoal_Response__Sequence
{
  avig_msg__action__MoverA_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__action__MoverA_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/MoverA in the package avig_msg.
typedef struct avig_msg__action__MoverA_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} avig_msg__action__MoverA_GetResult_Request;

// Struct for a sequence of avig_msg__action__MoverA_GetResult_Request.
typedef struct avig_msg__action__MoverA_GetResult_Request__Sequence
{
  avig_msg__action__MoverA_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__action__MoverA_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "avig_msg/action/detail/mover_a__struct.h"

/// Struct defined in action/MoverA in the package avig_msg.
typedef struct avig_msg__action__MoverA_GetResult_Response
{
  int8_t status;
  avig_msg__action__MoverA_Result result;
} avig_msg__action__MoverA_GetResult_Response;

// Struct for a sequence of avig_msg__action__MoverA_GetResult_Response.
typedef struct avig_msg__action__MoverA_GetResult_Response__Sequence
{
  avig_msg__action__MoverA_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__action__MoverA_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "avig_msg/action/detail/mover_a__struct.h"

/// Struct defined in action/MoverA in the package avig_msg.
typedef struct avig_msg__action__MoverA_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  avig_msg__action__MoverA_Feedback feedback;
} avig_msg__action__MoverA_FeedbackMessage;

// Struct for a sequence of avig_msg__action__MoverA_FeedbackMessage.
typedef struct avig_msg__action__MoverA_FeedbackMessage__Sequence
{
  avig_msg__action__MoverA_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} avig_msg__action__MoverA_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AVIG_MSG__ACTION__DETAIL__MOVER_A__STRUCT_H_
