# Contributing to GPAI

## Code of conduct

We welcome contributions from everyone, and to ensure our community stays open and healthy
we adhere to the [Contributor Covenant](https://www.contributor-covenant.org/), a widely
used [code of conduct](/CODE_OF_CONDUCT.md) adopted by many other communities such as
Linux, Ruby on Rails and GitLab.

Everyone participating in the GPAI community is expected to follow the code of conduct.

If someone in the community happens to be violating these terms, please let the project
leads know, and we will address it as soon as possible.

## License

GPAI is licensed under Apache 2, and thus all contributions will be licensed as such
as per clause 5 of the Apache 2 License:

~~~
5. Submission of Contributions. Unless You explicitly state otherwise,
   any Contribution intentionally submitted for inclusion in the Work
   by You to the Licensor shall be under the terms and conditions of
   this License, without any additional terms or conditions.
   Notwithstanding the above, nothing herein shall supersede or modify
   the terms of any separate license agreement you may have executed
   with Licensor regarding such Contributions.
~~~

Here is an example copyright header to add to the top of a new file:

```
Copyright [YEAR] The GPAI Contributors

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```

This assigns the copyright to The GPAI Contributors. If the contribution is made by individuals or
by a company wishing to retain the copyright, then use the following copyright notice at the top of the file:

```
Copyright [First year of contribution]-[Most recent year of contribution] Most recent author, previous authors
```

Concrete examples:

1. If Company X contributes code in 2023, use `Copyright 2023 Company X`.
2. If Company X contributes code in 2019 and modifies it in 2023, use `Copyright 2019-2023 Company X`
3. If Company X contributes code in 2019 and Company Y modifies it in 2023, use `Copyright 2019-2023 Company Y, Company X`
4. If Company X and Company Y contribute in a joint effort, use `Copyright 2023 Company X, Company Y`

## Tenants

GPAI is governed by a strict set of tenants which are listed below. Each
developer must read and agree to the below tenants before a Pull Request
will be accepted from that developer.

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

