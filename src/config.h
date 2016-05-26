#include <pebble.h>

#define BG_COLOR PBL_IF_COLOR_ELSE(GColorBrightGreen, GColorWhite)
#define TEXT_COLOR PBL_IF_COLOR_ELSE(GColorDukeBlue, GColorBlack)

#define EMPTY_MARKER "o"
#define HOUR_MARKER "h"
#define MINUTE_MARKER "m"
#define OVERLAP_MARKER "x"

#define DISPLAY_RADIUS 60
#define INSET PBL_IF_ROUND_ELSE(20, 12)

#define TEXT_LAYER_WIDTH 30
#define TEXT_LAYER_HEIGHT 38
#define TEXT_FONT FONT_KEY_DROID_SERIF_28_BOLD   
