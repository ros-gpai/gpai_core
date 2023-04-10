# Contributing to GPAI

All developers must read and agree to the below tenants before a Pull Request will be accepted
from that developer.

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

