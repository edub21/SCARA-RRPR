// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from avig_msg:srv/Heuristica.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__SRV__DETAIL__HEURISTICA__BUILDER_HPP_
#define AVIG_MSG__SRV__DETAIL__HEURISTICA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "avig_msg/srv/detail/heuristica__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace avig_msg
{

namespace srv
{

namespace builder
{

class Init_Heuristica_Request_tags_in
{
public:
  Init_Heuristica_Request_tags_in()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::avig_msg::srv::Heuristica_Request tags_in(::avig_msg::srv::Heuristica_Request::_tags_in_type arg)
  {
    msg_.tags_in = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::srv::Heuristica_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::srv::Heuristica_Request>()
{
  return avig_msg::srv::builder::Init_Heuristica_Request_tags_in();
}

}  // namespace avig_msg


namespace avig_msg
{

namespace srv
{

namespace builder
{

class Init_Heuristica_Response_tag_out
{
public:
  Init_Heuristica_Response_tag_out()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::avig_msg::srv::Heuristica_Response tag_out(::avig_msg::srv::Heuristica_Response::_tag_out_type arg)
  {
    msg_.tag_out = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::srv::Heuristica_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::srv::Heuristica_Response>()
{
  return avig_msg::srv::builder::Init_Heuristica_Response_tag_out();
}

}  // namespace avig_msg

#endif  // AVIG_MSG__SRV__DETAIL__HEURISTICA__BUILDER_HPP_
