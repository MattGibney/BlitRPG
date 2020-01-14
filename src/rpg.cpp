#include <string>
#include <string.h>
#include <memory>
#include <cstdlib>

#include "rpg.hpp"

using namespace blit;

void init() {}

void render(uint32_t time_ms) {
  // Set Background
  fb.pen(rgba(0, 0, 0, 255)); // #000000
  fb.clear(); // Fill the screen with the current pen colour

  fb.pen(rgba(255, 255, 255, 255)); // #FFFFFF
  fb.text("Hello World", &minimal_font[0][0], point(0, 0));
}

void update(uint32_t current_time) {}
