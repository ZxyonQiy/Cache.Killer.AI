#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
   FILE *log = fopen("/storage/emulated/0/Android/CacheKiller.log", "r");
     fseek(log, 0L, SEEK_END);
       long int size = ftell(log);

   if (size >= 10000) {
     system("for resetlog in /storage/emulated/0/Android/CacheKiller.log; do rm -rf \"$resetlog\"; done > /dev/null 2>&1");
   } else {
  }
  fclose(log);
 return 0;
}