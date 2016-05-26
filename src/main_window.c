#include <pebble.h>
#include "config.h"
#include "main_window.h"

Window *s_window;
int s_hours, s_minutes;
Marker s_markers[12];

static int32_t get_angle_for_hour(int hour) {
  return (hour * 360) / 12;
}

static int32_t get_angle_for_minute(int minute) {
  return get_angle_for_hour(minute / 5);
}

static void update_markers() {
  int32_t hour_position = get_angle_for_hour(s_hours) / 30;
  int32_t minute_position = get_angle_for_minute(s_minutes) / 30;

  for(int i = 0; i < 12; i++) {
    if(i == hour_position && i == minute_position) {
      snprintf(s_markers[i].text_buffer, 2, "%s", OVERLAP_MARKER);
    } else if(i == hour_position) {
      snprintf(s_markers[i].text_buffer, 2, "%s", HOUR_MARKER);
    } else if(i == minute_position) {
      snprintf(s_markers[i].text_buffer, 2, "%s", MINUTE_MARKER);
    } else {
      snprintf(s_markers[i].text_buffer, 2, "%s", EMPTY_MARKER);
    }

    text_layer_set_text(s_markers[i].text_layer, s_markers[i].text_buffer);
  }
}

static void initialise_marker(GRect bounds, Marker *marker, int32_t hour) {
  int32_t angle = get_angle_for_hour(hour);
  
  GRect marker_bounds = grect_centered_from_polar(bounds, GOvalScaleModeFitCircle, DEG_TO_TRIGANGLE(angle), GSize(TEXT_LAYER_WIDTH, TEXT_LAYER_HEIGHT));
  
  marker->text_layer = text_layer_create(marker_bounds);
  text_layer_set_background_color(marker->text_layer, GColorClear);
  text_layer_set_text_color(marker->text_layer, TEXT_COLOR);
  text_layer_set_text_alignment(marker->text_layer, GTextAlignmentCenter);
  text_layer_set_font(marker->text_layer, fonts_get_system_font(TEXT_FONT));
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = grect_inset(layer_get_bounds(window_layer), GEdgeInsets(INSET));
  
  for(int i = 0; i < 12; i++) {
    initialise_marker(bounds, &s_markers[i], i);
    layer_add_child(window_layer, text_layer_get_layer(s_markers[i].text_layer));
  }
  
  update_markers();
}

static void window_unload(Window *window) {
  for(int i = 0; i < 12; i++) {
    text_layer_destroy(s_markers[i].text_layer);
  }

  window_destroy(s_window);
}

void main_window_push() {
  s_window = window_create();
  window_set_background_color(s_window, BG_COLOR);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  window_stack_push(s_window, true);
}

void main_window_update(int32_t hours, int32_t minutes) {
  s_hours = hours;
  s_minutes = minutes;
  update_markers();
}