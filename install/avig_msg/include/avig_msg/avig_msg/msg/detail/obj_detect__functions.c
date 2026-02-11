// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from avig_msg:msg/ObjDetect.idl
// generated code does not contain a copyright notice
#include "avig_msg/msg/detail/obj_detect__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
avig_msg__msg__ObjDetect__init(avig_msg__msg__ObjDetect * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // posx
  // posy
  // orden
  // dist
  // orient
  return true;
}

void
avig_msg__msg__ObjDetect__fini(avig_msg__msg__ObjDetect * msg)
{
  if (!msg) {
    return;
  }
  // id
  // posx
  // posy
  // orden
  // dist
  // orient
}

bool
avig_msg__msg__ObjDetect__are_equal(const avig_msg__msg__ObjDetect * lhs, const avig_msg__msg__ObjDetect * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // posx
  if (lhs->posx != rhs->posx) {
    return false;
  }
  // posy
  if (lhs->posy != rhs->posy) {
    return false;
  }
  // orden
  if (lhs->orden != rhs->orden) {
    return false;
  }
  // dist
  if (lhs->dist != rhs->dist) {
    return false;
  }
  // orient
  if (lhs->orient != rhs->orient) {
    return false;
  }
  return true;
}

bool
avig_msg__msg__ObjDetect__copy(
  const avig_msg__msg__ObjDetect * input,
  avig_msg__msg__ObjDetect * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // posx
  output->posx = input->posx;
  // posy
  output->posy = input->posy;
  // orden
  output->orden = input->orden;
  // dist
  output->dist = input->dist;
  // orient
  output->orient = input->orient;
  return true;
}

avig_msg__msg__ObjDetect *
avig_msg__msg__ObjDetect__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  avig_msg__msg__ObjDetect * msg = (avig_msg__msg__ObjDetect *)allocator.allocate(sizeof(avig_msg__msg__ObjDetect), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(avig_msg__msg__ObjDetect));
  bool success = avig_msg__msg__ObjDetect__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
avig_msg__msg__ObjDetect__destroy(avig_msg__msg__ObjDetect * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    avig_msg__msg__ObjDetect__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
avig_msg__msg__ObjDetect__Sequence__init(avig_msg__msg__ObjDetect__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  avig_msg__msg__ObjDetect * data = NULL;

  if (size) {
    data = (avig_msg__msg__ObjDetect *)allocator.zero_allocate(size, sizeof(avig_msg__msg__ObjDetect), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = avig_msg__msg__ObjDetect__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        avig_msg__msg__ObjDetect__fini(&data[i - 1]);
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
avig_msg__msg__ObjDetect__Sequence__fini(avig_msg__msg__ObjDetect__Sequence * array)
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
      avig_msg__msg__ObjDetect__fini(&array->data[i]);
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

avig_msg__msg__ObjDetect__Sequence *
avig_msg__msg__ObjDetect__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  avig_msg__msg__ObjDetect__Sequence * array = (avig_msg__msg__ObjDetect__Sequence *)allocator.allocate(sizeof(avig_msg__msg__ObjDetect__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = avig_msg__msg__ObjDetect__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
avig_msg__msg__ObjDetect__Sequence__destroy(avig_msg__msg__ObjDetect__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    avig_msg__msg__ObjDetect__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
avig_msg__msg__ObjDetect__Sequence__are_equal(const avig_msg__msg__ObjDetect__Sequence * lhs, const avig_msg__msg__ObjDetect__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!avig_msg__msg__ObjDetect__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
avig_msg__msg__ObjDetect__Sequence__copy(
  const avig_msg__msg__ObjDetect__Sequence * input,
  avig_msg__msg__ObjDetect__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(avig_msg__msg__ObjDetect);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    avig_msg__msg__ObjDetect * data =
      (avig_msg__msg__ObjDetect *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!avig_msg__msg__ObjDetect__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          avig_msg__msg__ObjDetect__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!avig_msg__msg__ObjDetect__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
