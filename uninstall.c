#include <stdio.h>
#include <stdlib.h>

int main() {
   system("find /data/media/0/Android -name \"*CacheKiller.log*\" | while read -r cachelog; do rm -rf \"$cachelog\"; done > /dev/null 2>&1");
return 0;
}