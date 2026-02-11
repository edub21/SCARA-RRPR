// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from avig_msg:msg/AprilTagPixel.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL__BUILDER_HPP_
#define AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "avig_msg/msg/detail/april_tag_pixel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace avig_msg
{

namespace msg
{

namespace builder
{

class Init_AprilTagPixel_orient
{
public:
  explicit Init_AprilTagPixel_orient(::avig_msg::msg::AprilTagPixel & msg)
  : msg_(msg)
  {}
  ::avig_msg::msg::AprilTagPixel orient(::avig_msg::msg::AprilTagPixel::_orient_type arg)
  {
    msg_.orient = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::msg::AprilTagPixel msg_;
};

class Init_AprilTagPixel_dist
{
public:
  explicit Init_AprilTagPixel_dist(::avig_msg::msg::AprilTagPixel & msg)
  : msg_(msg)
  {}
  Init_AprilTagPixel_orient dist(::avig_msg::msg::AprilTagPixel::_dist_type arg)
  {
    msg_.dist = std::move(arg);
    return Init_AprilTagPixel_orient(msg_);
  }

private:
  ::avig_msg::msg::AprilTagPixel msg_;
};

class Init_AprilTagPixel_orden
{
public:
  explicit Init_AprilTagPixel_orden(::avig_msg::msg::AprilTagPixel & msg)
  : msg_(msg)
  {}
  Init_AprilTagPixel_dist orden(::avig_msg::msg::AprilTagPixel::_orden_type arg)
  {
    msg_.orden = std::move(arg);
    return Init_AprilTagPixel_dist(msg_);
  }

private:
  ::avig_msg::msg::AprilTagPixel msg_;
};

class Init_AprilTagPixel_posy
{
public:
  explicit Init_AprilTagPixel_posy(::avig_msg::msg::AprilTagPixel & msg)
  : msg_(msg)
  {}
  Init_AprilTagPixel_orden posy(::avig_msg::msg::AprilTagPixel::_posy_type arg)
  {
    msg_.posy = std::move(arg);
    return Init_AprilTagPixel_orden(msg_);
  }

private:
  ::avig_msg::msg::AprilTagPixel msg_;
};

class Init_AprilTagPixel_posx
{
public:
  explicit Init_AprilTagPixel_posx(::avig_msg::msg::AprilTagPixel & msg)
  : msg_(msg)
  {}
  Init_AprilTagPixel_posy posx(::avig_msg::msg::AprilTagPixel::_posx_type arg)
  {
    msg_.posx = std::move(arg);
    return Init_AprilTagPixel_posy(msg_);
  }

private:
  ::avig_msg::msg::AprilTagPixel msg_;
};

class Init_AprilTagPixel_id
{
public:
  Init_AprilTagPixel_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AprilTagPixel_posx id(::avig_msg::msg::AprilTagPixel::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_AprilTagPixel_posx(msg_);
  }

private:
  ::avig_msg::msg::AprilTagPixel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::msg::AprilTagPixel>()
{
  return avig_msg::msg::builder::Init_AprilTagPixel_id();
}

}  // namespace avig_msg

#endif  // AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL__BUILDER_HPP_
