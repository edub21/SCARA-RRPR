// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from avig_msg:srv/Heuristica.idl
// generated code does not contain a copyright notice
#include "avig_msg/srv/detail/heuristica__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `tags_in`
#include "avig_msg/msg/detail/april_tag_pixel_array__functions.h"

bool
avig_msg__srv__Heuristica_Request__init(avig_msg__srv__Heuristica_Request * msg)
{
  if (!msg) {
    return false;
  }
  // tags_in
  if (!avig_msg__msg__AprilTagPixelArray__init(&msg->tags_in)) {
    avig_msg__srv__Heuristica_Request__fini(msg);
    return false;
  }
  return true;
}

void
avig_msg__srv__Heuristica_Request__fini(avig_msg__srv__Heuristica_Request * msg)
{
  if (!msg) {
    return;
  }
  // tags_in
  avig_msg__msg__AprilTagPixelArray__fini(&msg->tags_in);
}

bool
avig_msg__srv__Heuristica_Request__are_equal(const avig_msg__srv__Heuristica_Request * lhs, const avig_msg__srv__Heuristica_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tags_in
  if (!avig_msg__msg__AprilTagPixelArray__are_equal(
      &(lhs->tags_in), &(rhs->tags_in)))
  {
    return false;
  }
  return true;
}

bool
avig_msg__srv__Heuristica_Request__copy(
  const avig_msg__srv__Heuristica_Request * input,
  avig_msg__srv__Heuristica_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // tags_in
  if (!avig_msg__msg__AprilTagPixelArray__copy(
      &(input->tags_in), &(output->tags_in)))
  {
    return false;
  }
  return true;
}

avig_msg__srv__Heuristica_Request *
avig_msg__srv__Heuristica_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  avig_msg__srv__Heuristica_Request * msg = (avig_msg__srv__Heuristica_Request *)allocator.allocate(sizeof(avig_msg__srv__Heuristica_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(avig_msg__srv__Heuristica_Request));
  bool success = avig_msg__srv__Heuristica_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
avig_msg__srv__Heuristica_Request__destroy(avig_msg__srv__Heuristica_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    avig_msg__srv__Heuristica_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
avig_msg__srv__Heuristica_Request__Sequence__init(avig_msg__srv__Heuristica_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  avig_msg__srv__Heuristica_Request * data = NULL;

  if (size) {
    data = (avig_msg__srv__Heuristica_Request *)allocator.zero_allocate(size, sizeof(avig_msg__srv__Heuristica_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = avig_msg__srv__Heuristica_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        avig_msg__srv__Heuristica_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
avig_msg__srv__Heuristica_Request__Sequence__fini(avig_msg__srv__Heuristica_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      avig_msg__srv__Heuristica_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

avig_msg__srv__Heuristica_Request__Sequence *
avig_msg__srv__Heuristica_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  avig_msg__srv__Heuristica_Request__Sequence * array = (avig_msg__srv__Heuristica_Request__Sequence *)allocator.allocate(sizeof(avig_msg__srv__Heuristica_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = avig_msg__srv__Heuristica_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
avig_msg__srv__Heuristica_Request__Sequence__destroy(avig_msg__srv__Heuristica_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    avig_msg__srv__Heuristica_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
avig_msg__srv__Heuristica_Request__Sequence__are_equal(const avig_msg__srv__Heuristica_Request__Sequence * lhs, const avig_msg__srv__Heuristica_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!avig_msg__srv__Heuristica_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
avig_msg__srv__Heuristica_Request__Sequence__copy(
  const avig_msg__srv__Heuristica_Request__Sequence * input,
  avig_msg__srv__Heuristica_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(avig_msg__srv__Heuristica_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    avig_msg__srv__Heuristica_Request * data =
      (avig_msg__srv__Heuristica_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!avig_msg__srv__Heuristica_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          avig_msg__srv__Heuristica_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!avig_msg__srv__Heuristica_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `tag_out`
#include "avig_msg/msg/detail/april_tag_pixel__functions.h"

bool
avig_msg__srv__Heuristica_Response__init(avig_msg__srv__Heuristica_Response * msg)
{
  if (!msg) {
    return false;
  }
  // tag_out
  if (!avig_msg__msg__AprilTagPixel__init(&msg->tag_out)) {
    avig_msg__srv__Heuristica_Response__fini(msg);
    return false;
  }
  return true;
}

void
avig_msg__srv__Heuristica_Response__fini(avig_msg__srv__Heuristica_Response * msg)
{
  if (!msg) {
    return;
  }
  // tag_out
  avig_msg__msg__AprilTagPixel__fini(&msg->tag_out);
}

bool
avig_msg__srv__Heuristica_Response__are_equal(const avig_msg__srv__Heuristica_Response * lhs, const avig_msg__srv__Heuristica_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tag_out
  if (!avig_msg__msg__AprilTagPixel__are_equal(
      &(lhs->tag_out), &(rhs->tag_out)))
  {
    return false;
  }
  return true;
}

bool
avig_msg__srv__Heuristica_Response__copy(
  const avig_msg__srv__Heuristica_Response * input,
  avig_msg__srv__Heuristica_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // tag_out
  if (!avig_msg__msg__AprilTagPixel__copy(
      &(input->tag_out), &(output->tag_out)))
  {
    return false;
  }
  return true;
}

avig_msg__srv__Heuristica_Response *
avig_msg__srv__Heuristica_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  avig_msg__srv__Heuristica_Response * msg = (avig_msg__srv__Heuristica_Response *)allocator.allocate(sizeof(avig_msg__srv__Heuristica_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(avig_msg__srv__Heuristica_Response));
  bool success = avig_msg__srv__Heuristica_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
avig_msg__srv__Heuristica_Response__destroy(avig_msg__srv__Heuristica_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    avig_msg__srv__Heuristica_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
avig_msg__srv__Heuristica_Response__Sequence__init(avig_msg__srv__Heuristica_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  avig_msg__srv__Heuristica_Response * data = NULL;

  if (size) {
    data = (avig_msg__srv__Heuristica_Response *)allocator.zero_allocate(size, sizeof(avig_msg__srv__Heuristica_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = avig_msg__srv__Heuristica_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        avig_msg__srv__Heuristica_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
avig_msg__srv__Heuristica_Response__Sequence__fini(avig_msg__srv__Heuristica_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      avig_msg__srv__Heuristica_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

avig_msg__srv__Heuristica_Response__Sequence *
avig_msg__srv__Heuristica_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  avig_msg__srv__Heuristica_Response__Sequence * array = (avig_msg__srv__Heuristica_Response__Sequence *)allocator.allocate(sizeof(avig_msg__srv__Heuristica_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = avig_msg__srv__Heuristica_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
avig_msg__srv__Heuristica_Response__Sequence__destroy(avig_msg__srv__Heuristica_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    avig_msg__srv__Heuristica_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
avig_msg__srv__Heuristica_Response__Sequence__are_equal(const avig_msg__srv__Heuristica_Response__Sequence * lhs, const avig_msg__srv__Heuristica_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!avig_msg__srv__Heuristica_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
avig_msg__srv__Heuristica_Response__Sequence__copy(
  const avig_msg__srv__Heuristica_Response__Sequence * input,
  avig_msg__srv__Heuristica_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(avig_msg__srv__Heuristica_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    avig_msg__srv__Heuristica_Response * data =
      (avig_msg__srv__Heuristica_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!avig_msg__srv__Heuristica_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          avig_msg__srv__Heuristica_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!avig_msg__srv__Heuristica_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
