// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from avig_msg:msg/AprilTagPixelArray.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__BUILDER_HPP_
#define AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "avig_msg/msg/detail/april_tag_pixel_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace avig_msg
{

namespace msg
{

namespace builder
{

class Init_AprilTagPixelArray_tags
{
public:
  Init_AprilTagPixelArray_tags()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::avig_msg::msg::AprilTagPixelArray tags(::avig_msg::msg::AprilTagPixelArray::_tags_type arg)
  {
    msg_.tags = std::move(arg);
    return std::move(msg_);
  }

private:
  ::avig_msg::msg::AprilTagPixelArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::avig_msg::msg::AprilTagPixelArray>()
{
  return avig_msg::msg::builder::Init_AprilTagPixelArray_tags();
}

}  // namespace avig_msg

#endif  // AVIG_MSG__MSG__DETAIL__APRIL_TAG_PIXEL_ARRAY__BUILDER_HPP_
