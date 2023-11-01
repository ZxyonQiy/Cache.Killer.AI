#!/bin/sh

       if [ -d "/data/media/0/Android" ]; then
       file=$(find /data/media/0/Android -name "*CacheKiller.log*")
       rm -rf "$file"
       fi
