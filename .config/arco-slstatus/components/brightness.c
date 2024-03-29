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
        uintmax_t current_brightness, max_brightness;
        if (pscanf("/sys/class/backlight/intel_backlight/brightness", "%ju", &current_brightness) != 1 ||
            pscanf("/sys/class/backlight/intel_backlight/max_brightness", "%ju", &max_brightness) != 1)
        {
            return NULL;
        }

        if (max_brightness == 0) {
            warn("Max brightness is reported as 0, cannot calculate percentage.");
            return NULL;
        }

        double brightness_percentage = (double)current_brightness / max_brightness * 100;
        return fmt_human(brightness_percentage, 1000);
    }
#endif