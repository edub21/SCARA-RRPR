// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from avig_msg:action/MoverA.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__ACTION__DETAIL__MOVER_A__TRAITS_HPP_
#define AVIG_MSG__ACTION__DETAIL__MOVER_A__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "avig_msg/action/detail/mover_a__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace avig_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const MoverA_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: x_actual
  {
    out << "x_actual: ";
    rosidl_generator_traits::value_to_yaml(msg.x_actual, out);
    out << ", ";
  }

  // member: y_actual
  {
    out << "y_actual: ";
    rosidl_generator_traits::value_to_yaml(msg.y_actual, out);
    out << ", ";
  }

  // member: x_meta
  {
    out << "x_meta: ";
    rosidl_generator_traits::value_to_yaml(msg.x_meta, out);
    out << ", ";
  }

  // member: y_meta
  {
    out << "y_meta: ";
    rosidl_generator_traits::value_to_yaml(msg.y_meta, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoverA_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x_actual
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_actual: ";
    rosidl_generator_traits::value_to_yaml(msg.x_actual, out);
    out << "\n";
  }

  // member: y_actual
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_actual: ";
    rosidl_generator_traits::value_to_yaml(msg.y_actual, out);
    out << "\n";
  }

  // member: x_meta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_meta: ";
    rosidl_generator_traits::value_to_yaml(msg.x_meta, out);
    out << "\n";
  }

  // member: y_meta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_meta: ";
    rosidl_generator_traits::value_to_yaml(msg.y_meta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoverA_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace avig_msg

namespace rosidl_generator_traits
{

[[deprecated("use avig_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const avig_msg::action::MoverA_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::action::MoverA_Goal & msg)
{
  return avig_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::action::MoverA_Goal>()
{
  return "avig_msg::action::MoverA_Goal";
}

template<>
inline const char * name<avig_msg::action::MoverA_Goal>()
{
  return "avig_msg/action/MoverA_Goal";
}

template<>
struct has_fixed_size<avig_msg::action::MoverA_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<avig_msg::action::MoverA_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<avig_msg::action::MoverA_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace avig_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const MoverA_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoverA_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoverA_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace avig_msg

namespace rosidl_generator_traits
{

[[deprecated("use avig_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const avig_msg::action::MoverA_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::action::MoverA_Result & msg)
{
  return avig_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::action::MoverA_Result>()
{
  return "avig_msg::action::MoverA_Result";
}

template<>
inline const char * name<avig_msg::action::MoverA_Result>()
{
  return "avig_msg/action/MoverA_Result";
}

template<>
struct has_fixed_size<avig_msg::action::MoverA_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<avig_msg::action::MoverA_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<avig_msg::action::MoverA_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace avig_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const MoverA_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: distancia_restante
  {
    out << "distancia_restante: ";
    rosidl_generator_traits::value_to_yaml(msg.distancia_restante, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoverA_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: distancia_restante
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distancia_restante: ";
    rosidl_generator_traits::value_to_yaml(msg.distancia_restante, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoverA_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace avig_msg

namespace rosidl_generator_traits
{

[[deprecated("use avig_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const avig_msg::action::MoverA_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::action::MoverA_Feedback & msg)
{
  return avig_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::action::MoverA_Feedback>()
{
  return "avig_msg::action::MoverA_Feedback";
}

template<>
inline const char * name<avig_msg::action::MoverA_Feedback>()
{
  return "avig_msg/action/MoverA_Feedback";
}

template<>
struct has_fixed_size<avig_msg::action::MoverA_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<avig_msg::action::MoverA_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<avig_msg::action::MoverA_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "avig_msg/action/detail/mover_a__traits.hpp"

namespace avig_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const MoverA_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoverA_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoverA_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace avig_msg

namespace rosidl_generator_traits
{

[[deprecated("use avig_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const avig_msg::action::MoverA_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::action::MoverA_SendGoal_Request & msg)
{
  return avig_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::action::MoverA_SendGoal_Request>()
{
  return "avig_msg::action::MoverA_SendGoal_Request";
}

template<>
inline const char * name<avig_msg::action::MoverA_SendGoal_Request>()
{
  return "avig_msg/action/MoverA_SendGoal_Request";
}

template<>
struct has_fixed_size<avig_msg::action::MoverA_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<avig_msg::action::MoverA_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<avig_msg::action::MoverA_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<avig_msg::action::MoverA_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<avig_msg::action::MoverA_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace avig_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const MoverA_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoverA_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoverA_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace avig_msg

namespace rosidl_generator_traits
{

[[deprecated("use avig_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const avig_msg::action::MoverA_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::action::MoverA_SendGoal_Response & msg)
{
  return avig_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::action::MoverA_SendGoal_Response>()
{
  return "avig_msg::action::MoverA_SendGoal_Response";
}

template<>
inline const char * name<avig_msg::action::MoverA_SendGoal_Response>()
{
  return "avig_msg/action/MoverA_SendGoal_Response";
}

template<>
struct has_fixed_size<avig_msg::action::MoverA_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<avig_msg::action::MoverA_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<avig_msg::action::MoverA_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<avig_msg::action::MoverA_SendGoal>()
{
  return "avig_msg::action::MoverA_SendGoal";
}

template<>
inline const char * name<avig_msg::action::MoverA_SendGoal>()
{
  return "avig_msg/action/MoverA_SendGoal";
}

template<>
struct has_fixed_size<avig_msg::action::MoverA_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<avig_msg::action::MoverA_SendGoal_Request>::value &&
    has_fixed_size<avig_msg::action::MoverA_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<avig_msg::action::MoverA_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<avig_msg::action::MoverA_SendGoal_Request>::value &&
    has_bounded_size<avig_msg::action::MoverA_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<avig_msg::action::MoverA_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<avig_msg::action::MoverA_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<avig_msg::action::MoverA_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace avig_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const MoverA_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoverA_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoverA_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace avig_msg

namespace rosidl_generator_traits
{

[[deprecated("use avig_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const avig_msg::action::MoverA_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::action::MoverA_GetResult_Request & msg)
{
  return avig_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::action::MoverA_GetResult_Request>()
{
  return "avig_msg::action::MoverA_GetResult_Request";
}

template<>
inline const char * name<avig_msg::action::MoverA_GetResult_Request>()
{
  return "avig_msg/action/MoverA_GetResult_Request";
}

template<>
struct has_fixed_size<avig_msg::action::MoverA_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<avig_msg::action::MoverA_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<avig_msg::action::MoverA_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "avig_msg/action/detail/mover_a__traits.hpp"

namespace avig_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const MoverA_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoverA_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoverA_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace avig_msg

namespace rosidl_generator_traits
{

[[deprecated("use avig_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const avig_msg::action::MoverA_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::action::MoverA_GetResult_Response & msg)
{
  return avig_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::action::MoverA_GetResult_Response>()
{
  return "avig_msg::action::MoverA_GetResult_Response";
}

template<>
inline const char * name<avig_msg::action::MoverA_GetResult_Response>()
{
  return "avig_msg/action/MoverA_GetResult_Response";
}

template<>
struct has_fixed_size<avig_msg::action::MoverA_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<avig_msg::action::MoverA_Result>::value> {};

template<>
struct has_bounded_size<avig_msg::action::MoverA_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<avig_msg::action::MoverA_Result>::value> {};

template<>
struct is_message<avig_msg::action::MoverA_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<avig_msg::action::MoverA_GetResult>()
{
  return "avig_msg::action::MoverA_GetResult";
}

template<>
inline const char * name<avig_msg::action::MoverA_GetResult>()
{
  return "avig_msg/action/MoverA_GetResult";
}

template<>
struct has_fixed_size<avig_msg::action::MoverA_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<avig_msg::action::MoverA_GetResult_Request>::value &&
    has_fixed_size<avig_msg::action::MoverA_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<avig_msg::action::MoverA_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<avig_msg::action::MoverA_GetResult_Request>::value &&
    has_bounded_size<avig_msg::action::MoverA_GetResult_Response>::value
  >
{
};

template<>
struct is_service<avig_msg::action::MoverA_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<avig_msg::action::MoverA_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<avig_msg::action::MoverA_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "avig_msg/action/detail/mover_a__traits.hpp"

namespace avig_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const MoverA_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoverA_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoverA_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace avig_msg

namespace rosidl_generator_traits
{

[[deprecated("use avig_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const avig_msg::action::MoverA_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  avig_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use avig_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const avig_msg::action::MoverA_FeedbackMessage & msg)
{
  return avig_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<avig_msg::action::MoverA_FeedbackMessage>()
{
  return "avig_msg::action::MoverA_FeedbackMessage";
}

template<>
inline const char * name<avig_msg::action::MoverA_FeedbackMessage>()
{
  return "avig_msg/action/MoverA_FeedbackMessage";
}

template<>
struct has_fixed_size<avig_msg::action::MoverA_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<avig_msg::action::MoverA_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<avig_msg::action::MoverA_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<avig_msg::action::MoverA_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<avig_msg::action::MoverA_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<avig_msg::action::MoverA>
  : std::true_type
{
};

template<>
struct is_action_goal<avig_msg::action::MoverA_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<avig_msg::action::MoverA_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<avig_msg::action::MoverA_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // AVIG_MSG__ACTION__DETAIL__MOVER_A__TRAITS_HPP_
