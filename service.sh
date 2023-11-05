#!/bin/sh

while [ -z "$(resetprop sys.boot_completed)" ]; do
  sleep 5
done

/data/adb/modules/cachekiller/system/bin/cachekiller >/dev/null 2>&1

/data/adb/modules/cachekiller/system/bin/sizeinfo >/dev/null 2>&1