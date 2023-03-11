#!/bin/sh
[ "$(id -u)" != "0" ] && printf "Run me as root.\n" && exit 1
printf "You're about to install packr. Do you want to continue? Y/N\n> "; read U
[ "$U" != "Y" ] && printf "Exiting..\n" && exit 1
[ -f "Makefile" ] && make clean install && printf "Installed binary\n" || exit 1
scripts/prepare_env.sh # prepare_env
