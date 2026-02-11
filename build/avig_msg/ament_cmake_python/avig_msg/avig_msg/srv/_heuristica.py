# generated from rosidl_generator_py/resource/_idl.py.em
# with input from avig_msg:srv/Heuristica.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Heuristica_Request(type):
    """Metaclass of message 'Heuristica_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('avig_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'avig_msg.srv.Heuristica_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__heuristica__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__heuristica__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__heuristica__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__heuristica__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__heuristica__request

            from avig_msg.msg import AprilTagPixelArray
            if AprilTagPixelArray.__class__._TYPE_SUPPORT is None:
                AprilTagPixelArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Heuristica_Request(metaclass=Metaclass_Heuristica_Request):
    """Message class 'Heuristica_Request'."""

    __slots__ = [
        '_tags_in',
    ]

    _fields_and_field_types = {
        'tags_in': 'avig_msg/AprilTagPixelArray',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['avig_msg', 'msg'], 'AprilTagPixelArray'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from avig_msg.msg import AprilTagPixelArray
        self.tags_in = kwargs.get('tags_in', AprilTagPixelArray())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.tags_in != other.tags_in:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def tags_in(self):
        """Message field 'tags_in'."""
        return self._tags_in

    @tags_in.setter
    def tags_in(self, value):
        if __debug__:
            from avig_msg.msg import AprilTagPixelArray
            assert \
                isinstance(value, AprilTagPixelArray), \
                "The 'tags_in' field must be a sub message of type 'AprilTagPixelArray'"
        self._tags_in = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Heuristica_Response(type):
    """Metaclass of message 'Heuristica_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('avig_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'avig_msg.srv.Heuristica_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__heuristica__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__heuristica__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__heuristica__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__heuristica__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__heuristica__response

            from avig_msg.msg import AprilTagPixel
            if AprilTagPixel.__class__._TYPE_SUPPORT is None:
                AprilTagPixel.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Heuristica_Response(metaclass=Metaclass_Heuristica_Response):
    """Message class 'Heuristica_Response'."""

    __slots__ = [
        '_tag_out',
    ]

    _fields_and_field_types = {
        'tag_out': 'avig_msg/AprilTagPixel',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['avig_msg', 'msg'], 'AprilTagPixel'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from avig_msg.msg import AprilTagPixel
        self.tag_out = kwargs.get('tag_out', AprilTagPixel())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.tag_out != other.tag_out:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def tag_out(self):
        """Message field 'tag_out'."""
        return self._tag_out

    @tag_out.setter
    def tag_out(self, value):
        if __debug__:
            from avig_msg.msg import AprilTagPixel
            assert \
                isinstance(value, AprilTagPixel), \
                "The 'tag_out' field must be a sub message of type 'AprilTagPixel'"
        self._tag_out = value


class Metaclass_Heuristica(type):
    """Metaclass of service 'Heuristica'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('avig_msg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'avig_msg.srv.Heuristica')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__heuristica

            from avig_msg.srv import _heuristica
            if _heuristica.Metaclass_Heuristica_Request._TYPE_SUPPORT is None:
                _heuristica.Metaclass_Heuristica_Request.__import_type_support__()
            if _heuristica.Metaclass_Heuristica_Response._TYPE_SUPPORT is None:
                _heuristica.Metaclass_Heuristica_Response.__import_type_support__()


class Heuristica(metaclass=Metaclass_Heuristica):
    from avig_msg.srv._heuristica import Heuristica_Request as Request
    from avig_msg.srv._heuristica import Heuristica_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
