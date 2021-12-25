#!/bin/bash

export TIMEZONE=$(cat /etc/timezone)
export GROUP=$(id -gn)
export USER_ID=$(id -u)
export GROUP_ID=$(id -g)
export VIDEO_GROUP_ID=$(cut -d: -f3 < <(getent group video))

docker-compose up --detach
