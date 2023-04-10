ARG ROS_DISTRO=humble
FROM ros:$ROS_DISTRO

SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# hadolint ignore=DL3008
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        gettext-base \
        locales \
        keyboard-configuration && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
RUN locale-gen en_US.UTF-8; dpkg-reconfigure -f noninteractive locales
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US.UTF-8
ENV LC_ALL en_US.UTF-8

COPY apt-packages /tmp/
# hadolint ignore=DL3008,SC2002
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        $(cat /tmp/apt-packages | cut -d# -f1 | envsubst) && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/apt-packages

RUN echo 'ALL ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers; \
    echo 'Defaults env_keep += "DEBUG ROS_DISTRO"' >> /etc/sudoers

COPY bashrc-git-prompt /
RUN cat /bashrc-git-prompt >> /etc/skel/.bashrc && \
    rm /bashrc-git-prompt

# hadolint ignore=DL3005
RUN apt-get update && \
    apt-get -y upgrade && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

COPY env.sh /etc/profile.d/env.sh
COPY gitconfig /etc/gitconfig
COPY entrypoint /entrypoint
ENTRYPOINT ["/entrypoint"]
CMD ["/bin/sh", "-c", "trap 'exit 147' TERM; tail -f /dev/null & wait ${!}"]
