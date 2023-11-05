#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void SetLog(const char *Log) {
    FILE *file = fopen("/storage/emulated/0/Android/CacheKiller.log", "a");
    if (file) {
        fprintf(file, "%s\n", Log);
        fclose(file);
    }
}

void SetMode(const char *mode) {
    FILE *modeFile = fopen("/data/adb/modules/cachekiller/mode.txt", "w");
    if (modeFile) {
        fprintf(modeFile, "%s\n", mode);
        fclose(modeFile);
    }
}

char* GetMode() {
    FILE *modeFile = fopen("/data/adb/modules/cachekiller/mode.txt", "r");
    if (modeFile) {
        static char mode_put[516];
        fscanf(modeFile, "%s", mode_put);
        fclose(modeFile);
        return mode_put;
    }
    return NULL;
}

int main() {

  char diary[50];
  struct tm *tm_info;
  time_t t = time(NULL);
  tm_info = localtime(&t);
  strftime(diary, 50, "%Y-%m-%d %T", tm_info);

    while (system("resetprop sys.boot_completed") != 0) {
        sleep(5);
    }

    const char *Set = "unset";
    SetMode(Set);

    SetLog("ZxyonQiy : Cache Killer AI Modules");

    sleep(2);

    char *mode_put = GetMode();

  while (1) {
    if (system("window=$(dumpsys window); echo \"$window\" | grep mScreen | grep false") == 0) {
    sleep(2);
           SetMode("killer");
            SetLog("");
            SetLog(diary);
            system("for cache in /data/data/*/cache/*; do if [ -f \"$cache\" ] && [ -d \"$cache\" ]; then rm -rf \"$cache\"; fi; done > /dev/null 2>&1");
            system("for xtr in /storage/emulated/0/Android/data/*/cache/*; do if [ -f \"$xtr\" ] && [ -d \"$xtr\" ]; then rm -rf \"$xtr\"; fi; done > /dev/null 2>&1");
            SetLog("Cache Killer AI: Killer Mode");
            SetLog("ScreenOff Enable Mode");
    sleep(60);
   } else {
   sleep(2);
   if (system("window=$(dumpsys window); echo \"$window\" | grep mScreen | grep false") != 0) {
         SetMode("Normal");
          SetLog("");
          SetLog(diary);
          SetLog("Cache Killer AI: disable Mode");
          SetLog("ScreenOn disable Mode");
   sleep(2);
  }
 }
}
    return 0;
}