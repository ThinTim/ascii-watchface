#pragma once
#include <pebble.h>

#include "config.h"

void main_window_push();

void main_window_update(int32_t hours, int32_t minutes);

typedef struct {
  char text_buffer[2];
  TextLayer *text_layer;
} Marker;