# This message attempts to describe a semantic object as completely as possible
# including its real-world physical properties and relevant attributes of its
# current state with as few redundancies as possible. This message is unlikely
# to be completely populated by any single node which is why it includes plenty
# of flags indicating the availability and quality of included properties.

# NOTE ON COVARIANCES: By convention, an identity value in a covariance matrix
# with a numerical value of float64[MAX] indicates that the associated field
# value should be considered invalid. This helps to reduce the required number
# of availability and quality flags. For this reason, if any field in a group
# of fields referenced in a covariance matrix has a valid identity value, the
# COVARIANCES_VALID flag should be set to True for that field group and any
# invalid fields should have their variances set to float64[MAX].
#
# Example:
# For valid X and Y values but invalid Z value with no cross-field covariance,
# the 3x3 matrix might look like:
#
# [ 1.0  0.0           0.0
#   0.0  1.0           0.0
#   0.0  0.0  1.79769e+308 ]

std_msgs/Header header

# The probability of existence of the object in the range [0,1]
float32 existence_probability 0.0

bool existence_probability_used False

# A unique identifier for this object
#
# See http://en.wikipedia.org/wiki/Universally_unique_identifier and
# http://tools.ietf.org/html/rfc4122.html for more information.
# For generating in C++ on *nix and BSD see libuuid. For Python3 see
# https://docs.python.org/3/library/uuid.html.
unique_identifier_msgs/UUID uuid

bool uuid_used False

# A point at the centroid of the object
geometry_msgs/PoseWithCovariance centroid_pose

bool[5] centroid_pose_flags [False, False, False, False, False]

uint8 CENTROID_POSE_USED=0
uint8 CENTROID_POSE_POSITION_VALID=1
uint8 CENTROID_POSE_ORIENTATION_VALID=2
uint8 CENTROID_POSE_POSITION_COVARIANCES_VALID=3
uint8 CENTROID_POSE_ORIENTATION_COVARIANCES_VALID=4

# The exterior shape of the object
#
# The centroid of the object shape is defined by centroid_pose unless
# centroid_pose_flags[CENTROID_POSE_USED] is False, in which case the shape is
# centered around the origin of the frame defined in the header.
shape_msgs/SolidPrimitive shape

bool shape_used False

# Linear and angular velocities of the object
geometry_msgs/TwistWithCovariance twist

bool[5] twist_flags [False, False, False, False, False]

uint8 TWIST_USED=0
uint8 TWIST_LINEAR_VALID=1
uint8 TWIST_ANGULAR_VALID=2
uint8 TWIST_LINEAR_COVARIANCES_VALID=3
uint8 TWIST_ANGULAR_COVARIANCES_VALID=4

# Linear and angular accelerations of the object
geometry_msgs/AccelWithCovariance accel

bool[5] accel_flags [False, False, False, False, False]

uint8 ACCEL_USED=0
uint8 ACCEL_LINEAR_VALID=1
uint8 ACCEL_ANGULAR_VALID=2
uint8 ACCEL_LINEAR_COVARIANCES_VALID=3
uint8 ACCEL_ANGULAR_COVARIANCES_VALID=4
