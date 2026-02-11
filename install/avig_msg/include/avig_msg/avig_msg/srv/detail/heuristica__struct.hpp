// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from avig_msg:srv/Heuristica.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__SRV__DETAIL__HEURISTICA__STRUCT_HPP_
#define AVIG_MSG__SRV__DETAIL__HEURISTICA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'tags_in'
#include "avig_msg/msg/detail/april_tag_pixel_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__avig_msg__srv__Heuristica_Request __attribute__((deprecated))
#else
# define DEPRECATED__avig_msg__srv__Heuristica_Request __declspec(deprecated)
#endif

namespace avig_msg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Heuristica_Request_
{
  using Type = Heuristica_Request_<ContainerAllocator>;

  explicit Heuristica_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tags_in(_init)
  {
    (void)_init;
  }

  explicit Heuristica_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tags_in(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _tags_in_type =
    avig_msg::msg::AprilTagPixelArray_<ContainerAllocator>;
  _tags_in_type tags_in;

  // setters for named parameter idiom
  Type & set__tags_in(
    const avig_msg::msg::AprilTagPixelArray_<ContainerAllocator> & _arg)
  {
    this->tags_in = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    avig_msg::srv::Heuristica_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const avig_msg::srv::Heuristica_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<avig_msg::srv::Heuristica_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<avig_msg::srv::Heuristica_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      avig_msg::srv::Heuristica_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<avig_msg::srv::Heuristica_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      avig_msg::srv::Heuristica_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<avig_msg::srv::Heuristica_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<avig_msg::srv::Heuristica_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<avig_msg::srv::Heuristica_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__avig_msg__srv__Heuristica_Request
    std::shared_ptr<avig_msg::srv::Heuristica_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__avig_msg__srv__Heuristica_Request
    std::shared_ptr<avig_msg::srv::Heuristica_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Heuristica_Request_ & other) const
  {
    if (this->tags_in != other.tags_in) {
      return false;
    }
    return true;
  }
  bool operator!=(const Heuristica_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Heuristica_Request_

// alias to use template instance with default allocator
using Heuristica_Request =
  avig_msg::srv::Heuristica_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace avig_msg


// Include directives for member types
// Member 'tag_out'
#include "avig_msg/msg/detail/april_tag_pixel__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__avig_msg__srv__Heuristica_Response __attribute__((deprecated))
#else
# define DEPRECATED__avig_msg__srv__Heuristica_Response __declspec(deprecated)
#endif

namespace avig_msg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Heuristica_Response_
{
  using Type = Heuristica_Response_<ContainerAllocator>;

  explicit Heuristica_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tag_out(_init)
  {
    (void)_init;
  }

  explicit Heuristica_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tag_out(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _tag_out_type =
    avig_msg::msg::AprilTagPixel_<ContainerAllocator>;
  _tag_out_type tag_out;

  // setters for named parameter idiom
  Type & set__tag_out(
    const avig_msg::msg::AprilTagPixel_<ContainerAllocator> & _arg)
  {
    this->tag_out = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    avig_msg::srv::Heuristica_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const avig_msg::srv::Heuristica_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<avig_msg::srv::Heuristica_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<avig_msg::srv::Heuristica_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      avig_msg::srv::Heuristica_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<avig_msg::srv::Heuristica_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      avig_msg::srv::Heuristica_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<avig_msg::srv::Heuristica_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<avig_msg::srv::Heuristica_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<avig_msg::srv::Heuristica_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__avig_msg__srv__Heuristica_Response
    std::shared_ptr<avig_msg::srv::Heuristica_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__avig_msg__srv__Heuristica_Response
    std::shared_ptr<avig_msg::srv::Heuristica_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Heuristica_Response_ & other) const
  {
    if (this->tag_out != other.tag_out) {
      return false;
    }
    return true;
  }
  bool operator!=(const Heuristica_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Heuristica_Response_

// alias to use template instance with default allocator
using Heuristica_Response =
  avig_msg::srv::Heuristica_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace avig_msg

namespace avig_msg
{

namespace srv
{

struct Heuristica
{
  using Request = avig_msg::srv::Heuristica_Request;
  using Response = avig_msg::srv::Heuristica_Response;
};

}  // namespace srv

}  // namespace avig_msg

#endif  // AVIG_MSG__SRV__DETAIL__HEURISTICA__STRUCT_HPP_
