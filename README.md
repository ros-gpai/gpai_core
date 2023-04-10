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

## Tenants

GPAI is governed by a strict set of tenants which are listed below.

- All parts of the GPAI (code, documentation, scripts, etc.) are released open-source under the
  Apache 2.0 license.
- Release numbering for GPAI shall abide by [Symantic Versioning 2.0](https://semver.org/).
- All ROS packages in the GPAI shall be released on the ROS build farm. The schedule for releasing
  GPAI packages shall be:
  - On the occasion of a major or minor release.
  - On the last day of every 3rd month (beginning in January) if no major or minor releases have
    been made but at least one patch release has been made.
- Each GPAI module:
  - Has a well-documented, well-defined API. This API will not change between major releases (and
    is unlikely to change at all unless ROS changes drastically).
  - Shall not depend on other GPAI modules except `gpai_core`.
  - Shall have automated tests which produce reports for unit test coverage and documentation
    coverage.
- The `main` branch of each GPAI module:
  - Shall always maintain 100% code documentation coverage (e.g. `doxygen`).
  - Shall always maintain at least 80% code unit test coverage.
- All changes after the 0.1 release shall be introduced only through merge requests.
- Every merge request shall be reviewed by at least one maintainer.
- When a maintainer agrees to review a merge request, they should only do so if they believe they
  can perform the review in an objective and impartial manner.
- All documentation outside of code in GPAI shall be in Markdown or LaTeX formats.
- All commits shall be signed with a DCO or similar.
- The GPAI shall support the most recent LTS release of ROS2. The most recent non-LTS release may
  also be supported.
