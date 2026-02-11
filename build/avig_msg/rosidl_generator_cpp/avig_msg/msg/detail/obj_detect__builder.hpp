// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from avig_msg:msg/ObjDetect.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__MSG__DETAIL__OBJ_DETECT__BUILDER_HPP_
#define AVIG_MSG__MSG__DETAIL__OBJ_DETECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "avig_msg/msg/detail/obj_detect__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace avig_msg
{

namespace msg
{

namespace builder
{

class Init_ObjDetect_orient
{
public:
  explicit Init_ObjDetect_orient(::avig_msg::msg::ObjDetect & msg)
  : msg_(msg)
  {}
  ::avig_msg::msg::ObjDetect orient(::avig_msg::msg::ObjDetect::_orient_type arg)
  {
    msg_.orient = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::msg::ObjDetect msg_;
};

class Init_ObjDetect_dist
{
public:
  explicit Init_ObjDetect_dist(::avig_msg::msg::ObjDetect & msg)
  : msg_(msg)
  {}
  Init_ObjDetect_orient dist(::avig_msg::msg::ObjDetect::_dist_type arg)
  {
    msg_.dist = std::move(arg);
    return Init_ObjDetect_orient(msg_);
  }

private:
  ::avig_msg::msg::ObjDetect msg_;
};

class Init_ObjDetect_orden
{
public:
  explicit Init_ObjDetect_orden(::avig_msg::msg::ObjDetect & msg)
  : msg_(msg)
  {}
  Init_ObjDetect_dist orden(::avig_msg::msg::ObjDetect::_orden_type arg)
  {
    msg_.orden = std::move(arg);
    return Init_ObjDetect_dist(msg_);
  }

private:
  ::avig_msg::msg::ObjDetect msg_;
};

class Init_ObjDetect_posy
{
public:
  explicit Init_ObjDetect_posy(::avig_msg::msg::ObjDetect & msg)
  : msg_(msg)
  {}
  Init_ObjDetect_orden posy(::avig_msg::msg::ObjDetect::_posy_type arg)
  {
    msg_.posy = std::move(arg);
    return Init_ObjDetect_orden(msg_);
  }

private:
  ::avig_msg::msg::ObjDetect msg_;
};

class Init_ObjDetect_posx
{
public:
  explicit Init_ObjDetect_posx(::avig_msg::msg::ObjDetect & msg)
  : msg_(msg)
  {}
  Init_ObjDetect_posy posx(::avig_msg::msg::ObjDetect::_posx_type arg)
  {
    msg_.posx = std::move(arg);
    return Init_ObjDetect_posy(msg_);
  }

private:
  ::avig_msg::msg::ObjDetect msg_;
};

class Init_ObjDetect_id
{
public:
  Init_ObjDetect_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjDetect_posx id(::avig_msg::msg::ObjDetect::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_ObjDetect_posx(msg_);
  }

private:
  ::avig_msg::msg::ObjDetect msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::msg::ObjDetect>()
{
  return avig_msg::msg::builder::Init_ObjDetect_id();
}

}  // namespace avig_msg

#endif  // AVIG_MSG__MSG__DETAIL__OBJ_DETECT__BUILDER_HPP_
