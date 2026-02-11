// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from avig_msg:action/MoverA.idl
// generated code does not contain a copyright notice

#ifndef AVIG_MSG__ACTION__DETAIL__MOVER_A__STRUCT_HPP_
#define AVIG_MSG__ACTION__DETAIL__MOVER_A__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__avig_msg__action__MoverA_Goal __attribute__((deprecated))
#else
# define DEPRECATED__avig_msg__action__MoverA_Goal __declspec(deprecated)
#endif

namespace avig_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoverA_Goal_
{
  using Type = MoverA_Goal_<ContainerAllocator>;

  explicit MoverA_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_actual = 0.0f;
      this->y_actual = 0.0f;
      this->x_meta = 0.0f;
      this->y_meta = 0.0f;
    }
  }

  explicit MoverA_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_actual = 0.0f;
      this->y_actual = 0.0f;
      this->x_meta = 0.0f;
      this->y_meta = 0.0f;
    }
  }

  // field types and members
  using _x_actual_type =
    float;
  _x_actual_type x_actual;
  using _y_actual_type =
    float;
  _y_actual_type y_actual;
  using _x_meta_type =
    float;
  _x_meta_type x_meta;
  using _y_meta_type =
    float;
  _y_meta_type y_meta;

  // setters for named parameter idiom
  Type & set__x_actual(
    const float & _arg)
  {
    this->x_actual = _arg;
    return *this;
  }
  Type & set__y_actual(
    const float & _arg)
  {
    this->y_actual = _arg;
    return *this;
  }
  Type & set__x_meta(
    const float & _arg)
  {
    this->x_meta = _arg;
    return *this;
  }
  Type & set__y_meta(
    const float & _arg)
  {
    this->y_meta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    avig_msg::action::MoverA_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const avig_msg::action::MoverA_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__avig_msg__action__MoverA_Goal
    std::shared_ptr<avig_msg::action::MoverA_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__avig_msg__action__MoverA_Goal
    std::shared_ptr<avig_msg::action::MoverA_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoverA_Goal_ & other) const
  {
    if (this->x_actual != other.x_actual) {
      return false;
    }
    if (this->y_actual != other.y_actual) {
      return false;
    }
    if (this->x_meta != other.x_meta) {
      return false;
    }
    if (this->y_meta != other.y_meta) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoverA_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoverA_Goal_

// alias to use template instance with default allocator
using MoverA_Goal =
  avig_msg::action::MoverA_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace avig_msg


#ifndef _WIN32
# define DEPRECATED__avig_msg__action__MoverA_Result __attribute__((deprecated))
#else
# define DEPRECATED__avig_msg__action__MoverA_Result __declspec(deprecated)
#endif

namespace avig_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoverA_Result_
{
  using Type = MoverA_Result_<ContainerAllocator>;

  explicit MoverA_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit MoverA_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    avig_msg::action::MoverA_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const avig_msg::action::MoverA_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__avig_msg__action__MoverA_Result
    std::shared_ptr<avig_msg::action::MoverA_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__avig_msg__action__MoverA_Result
    std::shared_ptr<avig_msg::action::MoverA_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoverA_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoverA_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoverA_Result_

// alias to use template instance with default allocator
using MoverA_Result =
  avig_msg::action::MoverA_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace avig_msg


#ifndef _WIN32
# define DEPRECATED__avig_msg__action__MoverA_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__avig_msg__action__MoverA_Feedback __declspec(deprecated)
#endif

namespace avig_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoverA_Feedback_
{
  using Type = MoverA_Feedback_<ContainerAllocator>;

  explicit MoverA_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distancia_restante = 0.0f;
    }
  }

  explicit MoverA_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distancia_restante = 0.0f;
    }
  }

  // field types and members
  using _distancia_restante_type =
    float;
  _distancia_restante_type distancia_restante;

  // setters for named parameter idiom
  Type & set__distancia_restante(
    const float & _arg)
  {
    this->distancia_restante = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    avig_msg::action::MoverA_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const avig_msg::action::MoverA_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__avig_msg__action__MoverA_Feedback
    std::shared_ptr<avig_msg::action::MoverA_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__avig_msg__action__MoverA_Feedback
    std::shared_ptr<avig_msg::action::MoverA_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoverA_Feedback_ & other) const
  {
    if (this->distancia_restante != other.distancia_restante) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoverA_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoverA_Feedback_

// alias to use template instance with default allocator
using MoverA_Feedback =
  avig_msg::action::MoverA_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace avig_msg


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "avig_msg/action/detail/mover_a__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__avig_msg__action__MoverA_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__avig_msg__action__MoverA_SendGoal_Request __declspec(deprecated)
#endif

namespace avig_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoverA_SendGoal_Request_
{
  using Type = MoverA_SendGoal_Request_<ContainerAllocator>;

  explicit MoverA_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit MoverA_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    avig_msg::action::MoverA_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const avig_msg::action::MoverA_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__avig_msg__action__MoverA_SendGoal_Request
    std::shared_ptr<avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__avig_msg__action__MoverA_SendGoal_Request
    std::shared_ptr<avig_msg::action::MoverA_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoverA_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoverA_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoverA_SendGoal_Request_

// alias to use template instance with default allocator
using MoverA_SendGoal_Request =
  avig_msg::action::MoverA_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace avig_msg


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__avig_msg__action__MoverA_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__avig_msg__action__MoverA_SendGoal_Response __declspec(deprecated)
#endif

namespace avig_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoverA_SendGoal_Response_
{
  using Type = MoverA_SendGoal_Response_<ContainerAllocator>;

  explicit MoverA_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit MoverA_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__avig_msg__action__MoverA_SendGoal_Response
    std::shared_ptr<avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__avig_msg__action__MoverA_SendGoal_Response
    std::shared_ptr<avig_msg::action::MoverA_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoverA_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoverA_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoverA_SendGoal_Response_

// alias to use template instance with default allocator
using MoverA_SendGoal_Response =
  avig_msg::action::MoverA_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace avig_msg

namespace avig_msg
{

namespace action
{

struct MoverA_SendGoal
{
  using Request = avig_msg::action::MoverA_SendGoal_Request;
  using Response = avig_msg::action::MoverA_SendGoal_Response;
};

}  // namespace action

}  // namespace avig_msg


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__avig_msg__action__MoverA_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__avig_msg__action__MoverA_GetResult_Request __declspec(deprecated)
#endif

namespace avig_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoverA_GetResult_Request_
{
  using Type = MoverA_GetResult_Request_<ContainerAllocator>;

  explicit MoverA_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit MoverA_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__avig_msg__action__MoverA_GetResult_Request
    std::shared_ptr<avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__avig_msg__action__MoverA_GetResult_Request
    std::shared_ptr<avig_msg::action::MoverA_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoverA_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoverA_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoverA_GetResult_Request_

// alias to use template instance with default allocator
using MoverA_GetResult_Request =
  avig_msg::action::MoverA_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace avig_msg


// Include directives for member types
// Member 'result'
// already included above
// #include "avig_msg/action/detail/mover_a__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__avig_msg__action__MoverA_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__avig_msg__action__MoverA_GetResult_Response __declspec(deprecated)
#endif

namespace avig_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoverA_GetResult_Response_
{
  using Type = MoverA_GetResult_Response_<ContainerAllocator>;

  explicit MoverA_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit MoverA_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    avig_msg::action::MoverA_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const avig_msg::action::MoverA_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__avig_msg__action__MoverA_GetResult_Response
    std::shared_ptr<avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__avig_msg__action__MoverA_GetResult_Response
    std::shared_ptr<avig_msg::action::MoverA_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoverA_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoverA_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoverA_GetResult_Response_

// alias to use template instance with default allocator
using MoverA_GetResult_Response =
  avig_msg::action::MoverA_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace avig_msg

namespace avig_msg
{

namespace action
{

struct MoverA_GetResult
{
  using Request = avig_msg::action::MoverA_GetResult_Request;
  using Response = avig_msg::action::MoverA_GetResult_Response;
};

}  // namespace action

}  // namespace avig_msg


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "avig_msg/action/detail/mover_a__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__avig_msg__action__MoverA_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__avig_msg__action__MoverA_FeedbackMessage __declspec(deprecated)
#endif

namespace avig_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoverA_FeedbackMessage_
{
  using Type = MoverA_FeedbackMessage_<ContainerAllocator>;

  explicit MoverA_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit MoverA_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    avig_msg::action::MoverA_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const avig_msg::action::MoverA_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__avig_msg__action__MoverA_FeedbackMessage
    std::shared_ptr<avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__avig_msg__action__MoverA_FeedbackMessage
    std::shared_ptr<avig_msg::action::MoverA_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoverA_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoverA_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoverA_FeedbackMessage_

// alias to use template instance with default allocator
using MoverA_FeedbackMessage =
  avig_msg::action::MoverA_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace avig_msg

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace avig_msg
{

namespace action
{

struct MoverA
{
  /// The goal message defined in the action definition.
  using Goal = avig_msg::action::MoverA_Goal;
  /// The result message defined in the action definition.
  using Result = avig_msg::action::MoverA_Result;
  /// The feedback message defined in the action definition.
  using Feedback = avig_msg::action::MoverA_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = avig_msg::action::MoverA_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = avig_msg::action::MoverA_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = avig_msg::action::MoverA_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct MoverA MoverA;

}  // namespace action

}  // namespace avig_msg

#endif  // AVIG_MSG__ACTION__DETAIL__MOVER_A__STRUCT_HPP_
