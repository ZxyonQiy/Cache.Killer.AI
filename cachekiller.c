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
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);
    strftime(diary, 50, "%Y-%m-%d %T", tm_info);

    while (system("resetprop sys.boot_completed") != 0) {
        sleep(5);
    }

    const char *Set = "unset";
    SetMode(Set);

    SetLog("");
    SetLog("ZxyonQiy : Cache Killer AI Modules");

    sleep(2);

    const char *Select = "killer";
    SetMode(Select);

    char *mode_put = GetMode();

    if (mode_put != NULL && strcmp(mode_put, "killer") == 0) {
        while (1) {
          sleep(30);
            SetLog("");
            SetLog(diary);
            system("for cache in /data/data/*/cache/*; do if [ -f \"$cache\" ] && [ -d \"$cache\" ]; then rm -rf \"$cache\"; fi; done > /dev/null 2>&1; for c_cache in /data/data/*/code_cache/*; do if [ -f \"$c_cache\" ] && [ -d \"$c_cache\" ]; then rm -rf \"$c_cache\"; fi; done > /dev/null 2>&1");
            SetLog("Cache Killer AI: Killer Mode");
            SetLog("Success Killer Cache");
        }
    } else {
        SetLog("Failed Program");
    }

    return 0;
}