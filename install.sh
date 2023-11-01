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

sleep 3
  ui_print "- Settings file Cache Killer"
sleep 6
  mkdir -p "$MODPATH"/system/bin
  unzip -o "$ZIPFILE" 'cachekiller' -d "$MODPATH"/system/bin >&2
  chmod +x "$MODPATH"/system/bin/cachekiller
  
sleep 5
  ui_print ""
  ui_print "Complete Installed Modules."