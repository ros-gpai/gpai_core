# GPAI - the General Purpose Autonomy Infrastructure

The General Purpose Autonomy Infrastructure (GPAI - pronounced G-P-A-I or G-pie) is a ROS2-based
set of libraries, nodes, and interfaces designed to make the automation of mobile robots simpler.
GPAI abides by a set of core tenants which are described below. Additionally, GPAI is made up of
several "modules" (hosted as individual repositories) which are listed below.

## Modules

### `gpai_core` (this repository)

`gpai_core` contains system-level documentation as well as interfaces, libraries, and algorithms
which are used by all other GPAI modules.

### `gpai_platform`

`gpai_platform` contains algorithms and nodes which are designed to receive platform-type-specific
commands and interface with mobile robotics platforms. For more information,
visit https://github.com/ros-gpai/gpai_platform.

### `gpai_control`

`gpai_control` contains algorithms and nodes which are designed to receive platform-agnostic
trajectories and output platform-type-specific commands. For more information,
visit https://github.com/ros-gpai/gpai_control.

### `gpai_planning`

`gpai_planning` contains algorithms and nodes which are designed to receive localization estimates
and output platform-agnostic trajectories. For more information visit
https://github.com/ros-gpai/gpai_planning.

### `gpai_localization`

`gpai_localization` contains algorithms and nodes which are designed to receive platform-relative
and earth-relative sensor measurements and output filtered localization
estimates. For more information, visit https://github.com/ros-gpai/gpai_localization.

### `gpai_perception`

`gpai_perception` contains algorithms and nodes which are designed to receive raw sensor data from
sensors which perceive the environment around a mobile robot and output semantic
representations of those data. For more information visit
https://github.com/ros-gpai/gpai_perception.

## Contributing
All developers must read and agree to the tenants put forth in [CONTRIBUTING.md](CONTRIBUTING.md).
