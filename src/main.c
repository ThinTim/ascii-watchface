#include "main_window.h"

static void tick_handler(struct tm *time_now, TimeUnits changed) {
  int hour = time_now->tm_hour;
  
  //Convert from 24 to 12 hour time if needed
  hour -= (hour > 12) ? 12 : 0;
  
  main_window_update(hour, time_now->tm_min);
}

static void init() {
  main_window_push();

  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

static void deinit() {
  tick_timer_service_unsubscribe();
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}