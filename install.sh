#!/bin/sh

SKIPMOUNT=false
PROPFILE=false
POSTFSDATA=false
LATESTARTSERVICE=true

REPLACE=""

unzip -o "$ZIPFILE" 'AI' -d "$MODPATH" >&2
ui_print ""
ui_print ""
ui_print "$(awk '{print}' "$MODPATH/AI")"
ui_print ""
ui_print ""

sleep 3
  ui_print "- Extracting Modules ZIPFILES"
  unzip -o "$ZIPFILE" 'module.prop' -d "$MODPATH" >&2
  unzip -o "$ZIPFILE" 'service.sh' -d "$MODPATH" >&2

sleep 5
  ui_print "- Create file Cache Killer "
  echo "nohup KILLER > /dev/null 2>&1" > "$MODPATH"/service.sh

sleep 10
  ui_print "- Settings exec file Cache Killer"
  mkdir -p "$MODPATH"/system/bin
  unzip -o "$ZIPFILE" 'KILLER' -d "$MODPATH"/system/bin >&2
  chmod +x "$MODPATH"/system/bin/KILLER
  
sleep 5
  ui_print ""
  ui_print "Complete Installed Modules."