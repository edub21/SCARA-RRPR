// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from avig_msg:action/MoverA.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__ACTION__DETAIL__MOVER_A__BUILDER_HPP_
#define AVIG_MSG__ACTION__DETAIL__MOVER_A__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "avig_msg/action/detail/mover_a__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace avig_msg
{

namespace action
{

namespace builder
{

class Init_MoverA_Goal_y_meta
{
public:
  explicit Init_MoverA_Goal_y_meta(::avig_msg::action::MoverA_Goal & msg)
  : msg_(msg)
  {}
  ::avig_msg::action::MoverA_Goal y_meta(::avig_msg::action::MoverA_Goal::_y_meta_type arg)
  {
    msg_.y_meta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::action::MoverA_Goal msg_;
};

class Init_MoverA_Goal_x_meta
{
public:
  explicit Init_MoverA_Goal_x_meta(::avig_msg::action::MoverA_Goal & msg)
  : msg_(msg)
  {}
  Init_MoverA_Goal_y_meta x_meta(::avig_msg::action::MoverA_Goal::_x_meta_type arg)
  {
    msg_.x_meta = std::move(arg);
    return Init_MoverA_Goal_y_meta(msg_);
  }

private:
  ::avig_msg::action::MoverA_Goal msg_;
};

class Init_MoverA_Goal_y_actual
{
public:
  explicit Init_MoverA_Goal_y_actual(::avig_msg::action::MoverA_Goal & msg)
  : msg_(msg)
  {}
  Init_MoverA_Goal_x_meta y_actual(::avig_msg::action::MoverA_Goal::_y_actual_type arg)
  {
    msg_.y_actual = std::move(arg);
    return Init_MoverA_Goal_x_meta(msg_);
  }

private:
  ::avig_msg::action::MoverA_Goal msg_;
};

class Init_MoverA_Goal_x_actual
{
public:
  Init_MoverA_Goal_x_actual()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoverA_Goal_y_actual x_actual(::avig_msg::action::MoverA_Goal::_x_actual_type arg)
  {
    msg_.x_actual = std::move(arg);
    return Init_MoverA_Goal_y_actual(msg_);
  }

private:
  ::avig_msg::action::MoverA_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::action::MoverA_Goal>()
{
  return avig_msg::action::builder::Init_MoverA_Goal_x_actual();
}

}  // namespace avig_msg


namespace avig_msg
{

namespace action
{

namespace builder
{

class Init_MoverA_Result_success
{
public:
  Init_MoverA_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::avig_msg::action::MoverA_Result success(::avig_msg::action::MoverA_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::action::MoverA_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::action::MoverA_Result>()
{
  return avig_msg::action::builder::Init_MoverA_Result_success();
}

}  // namespace avig_msg


namespace avig_msg
{

namespace action
{

namespace builder
{

class Init_MoverA_Feedback_distancia_restante
{
public:
  Init_MoverA_Feedback_distancia_restante()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::avig_msg::action::MoverA_Feedback distancia_restante(::avig_msg::action::MoverA_Feedback::_distancia_restante_type arg)
  {
    msg_.distancia_restante = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::action::MoverA_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::action::MoverA_Feedback>()
{
  return avig_msg::action::builder::Init_MoverA_Feedback_distancia_restante();
}

}  // namespace avig_msg


namespace avig_msg
{

namespace action
{

namespace builder
{

class Init_MoverA_SendGoal_Request_goal
{
public:
  explicit Init_MoverA_SendGoal_Request_goal(::avig_msg::action::MoverA_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::avig_msg::action::MoverA_SendGoal_Request goal(::avig_msg::action::MoverA_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::action::MoverA_SendGoal_Request msg_;
};

class Init_MoverA_SendGoal_Request_goal_id
{
public:
  Init_MoverA_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoverA_SendGoal_Request_goal goal_id(::avig_msg::action::MoverA_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoverA_SendGoal_Request_goal(msg_);
  }

private:
  ::avig_msg::action::MoverA_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::action::MoverA_SendGoal_Request>()
{
  return avig_msg::action::builder::Init_MoverA_SendGoal_Request_goal_id();
}

}  // namespace avig_msg


namespace avig_msg
{

namespace action
{

namespace builder
{

class Init_MoverA_SendGoal_Response_stamp
{
public:
  explicit Init_MoverA_SendGoal_Response_stamp(::avig_msg::action::MoverA_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::avig_msg::action::MoverA_SendGoal_Response stamp(::avig_msg::action::MoverA_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::action::MoverA_SendGoal_Response msg_;
};

class Init_MoverA_SendGoal_Response_accepted
{
public:
  Init_MoverA_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoverA_SendGoal_Response_stamp accepted(::avig_msg::action::MoverA_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoverA_SendGoal_Response_stamp(msg_);
  }

private:
  ::avig_msg::action::MoverA_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::action::MoverA_SendGoal_Response>()
{
  return avig_msg::action::builder::Init_MoverA_SendGoal_Response_accepted();
}

}  // namespace avig_msg


namespace avig_msg
{

namespace action
{

namespace builder
{

class Init_MoverA_GetResult_Request_goal_id
{
public:
  Init_MoverA_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::avig_msg::action::MoverA_GetResult_Request goal_id(::avig_msg::action::MoverA_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::action::MoverA_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::action::MoverA_GetResult_Request>()
{
  return avig_msg::action::builder::Init_MoverA_GetResult_Request_goal_id();
}

}  // namespace avig_msg


namespace avig_msg
{

namespace action
{

namespace builder
{

class Init_MoverA_GetResult_Response_result
{
public:
  explicit Init_MoverA_GetResult_Response_result(::avig_msg::action::MoverA_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::avig_msg::action::MoverA_GetResult_Response result(::avig_msg::action::MoverA_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::action::MoverA_GetResult_Response msg_;
};

class Init_MoverA_GetResult_Response_status
{
public:
  Init_MoverA_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoverA_GetResult_Response_result status(::avig_msg::action::MoverA_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoverA_GetResult_Response_result(msg_);
  }

private:
  ::avig_msg::action::MoverA_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::action::MoverA_GetResult_Response>()
{
  return avig_msg::action::builder::Init_MoverA_GetResult_Response_status();
}

}  // namespace avig_msg


namespace avig_msg
{

namespace action
{

namespace builder
{

class Init_MoverA_FeedbackMessage_feedback
{
public:
  explicit Init_MoverA_FeedbackMessage_feedback(::avig_msg::action::MoverA_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::avig_msg::action::MoverA_FeedbackMessage feedback(::avig_msg::action::MoverA_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::action::MoverA_FeedbackMessage msg_;
};

class Init_MoverA_FeedbackMessage_goal_id
{
public:
  Init_MoverA_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoverA_FeedbackMessage_feedback goal_id(::avig_msg::action::MoverA_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoverA_FeedbackMessage_feedback(msg_);
  }

private:
  ::avig_msg::action::MoverA_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::action::MoverA_FeedbackMessage>()
{
  return avig_msg::action::builder::Init_MoverA_FeedbackMessage_goal_id();
}

}  // namespace avig_msg

#endif  // AVIG_MSG__ACTION__DETAIL__MOVER_A__BUILDER_HPP_
