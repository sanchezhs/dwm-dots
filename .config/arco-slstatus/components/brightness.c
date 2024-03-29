#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>

#include "../util.h"

#if defined (__linux__)
    // get brightness info
    const char *
    brightness(void)
    {
        uintmax_t brightness;
        if (pscanf("/sys/class/backlight/intel_backlight/brightness", "%ju", &brightness) != 1)
        {
            return NULL;
        }
        brightness = (int) brightness * 96000 / 100;
        if (brightness == 96000) {
            brightness = 100000;
        }

        return fmt_human(brightness, 1000);
    }
#endif