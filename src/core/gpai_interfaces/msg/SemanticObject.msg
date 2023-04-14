# This message attempts to describe a semantic object as completely as possible
# including its real-world physical properties, regulatory implications, and
# relevant attributes of its current state with as few redundancies as possible.
# This message is unlikely to be completely populated by any single node which is
# why it includes plenty of flags indicating the availability and quality of
# included properties.

std_msgs/Header header

# A point at the centroid of the object
geometry_msgs/PoseWithCovariance centroid_pose

bool[5] centroid_pose_flags [False, False, False, False, False]

uint8 CENTROID_POSE_USED=0
uint8 CENTROID_POSE_POSITION_VALID=1
uint8 CENTROID_POSE_ORIENTATION_VALID=2
uint8 CENTROID_POSE_POSITION_COVARIANCE_VALID=3
uint8 CENTROID_POSE_ORIENTATION_COVARIANCE_VALID=4
