#!/bin/bash

docker exec -it -u $USER -w $HOME $(docker container ls --filter 'name=gpai' --filter 'status=running' -q) /bin/bash
