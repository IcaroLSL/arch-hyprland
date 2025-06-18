#!/bin/bash

if ! pgrep -x "wofi" > /dev/null; then
    wofi -I --show drun --style /home/yoku/.config/wofi/style.css
fi
