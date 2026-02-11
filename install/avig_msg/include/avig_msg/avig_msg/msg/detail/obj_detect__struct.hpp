// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from avig_msg:msg/ObjDetect.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__MSG__DETAIL__OBJ_DETECT__STRUCT_HPP_
#define AVIG_MSG__MSG__DETAIL__OBJ_DETECT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__avig_msg__msg__ObjDetect __attribute__((deprecated))
#else
# define DEPRECATED__avig_msg__msg__ObjDetect __declspec(deprecated)
#endif

namespace avig_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjDetect_
{
  using Type = ObjDetect_<ContainerAllocator>;

  explicit ObjDetect_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->posx = 0.0f;
      this->posy = 0.0f;
      this->orden = 0l;
      this->dist = 0.0f;
      this->orient = 0.0f;
    }
  }

  explicit ObjDetect_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->posx = 0.0f;
      this->posy = 0.0f;
      this->orden = 0l;
      this->dist = 0.0f;
      this->orient = 0.0f;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _posx_type =
    float;
  _posx_type posx;
  using _posy_type =
    float;
  _posy_type posy;
  using _orden_type =
    int32_t;
  _orden_type orden;
  using _dist_type =
    float;
  _dist_type dist;
  using _orient_type =
    float;
  _orient_type orient;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__posx(
    const float & _arg)
  {
    this->posx = _arg;
    return *this;
  }
  Type & set__posy(
    const float & _arg)
  {
    this->posy = _arg;
    return *this;
  }
  Type & set__orden(
    const int32_t & _arg)
  {
    this->orden = _arg;
    return *this;
  }
  Type & set__dist(
    const float & _arg)
  {
    this->dist = _arg;
    return *this;
  }
  Type & set__orient(
    const float & _arg)
  {
    this->orient = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    avig_msg::msg::ObjDetect_<ContainerAllocator> *;
  using ConstRawPtr =
    const avig_msg::msg::ObjDetect_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<avig_msg::msg::ObjDetect_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<avig_msg::msg::ObjDetect_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      avig_msg::msg::ObjDetect_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<avig_msg::msg::ObjDetect_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      avig_msg::msg::ObjDetect_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<avig_msg::msg::ObjDetect_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<avig_msg::msg::ObjDetect_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<avig_msg::msg::ObjDetect_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__avig_msg__msg__ObjDetect
    std::shared_ptr<avig_msg::msg::ObjDetect_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__avig_msg__msg__ObjDetect
    std::shared_ptr<avig_msg::msg::ObjDetect_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjDetect_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->posx != other.posx) {
      return false;
    }
    if (this->posy != other.posy) {
      return false;
    }
    if (this->orden != other.orden) {
      return false;
    }
    if (this->dist != other.dist) {
      return false;
    }
    if (this->orient != other.orient) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjDetect_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjDetect_

// alias to use template instance with default allocator
using ObjDetect =
  avig_msg::msg::ObjDetect_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace avig_msg

#endif  // AVIG_MSG__MSG__DETAIL__OBJ_DETECT__STRUCT_HPP_
