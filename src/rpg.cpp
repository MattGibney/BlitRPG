#include "rpg.hpp"

#include "maps/overworld.hpp"

using namespace blit;

/**
 * Instantiate BlitRPG::Map class instance. This should be called with the 
 * required data.
 * 
 * Perhaps JSON?
 */
BlitRPG::Overworld overworld = BlitRPG::Overworld();

void init() {}

void render(uint32_t time_ms) {
  // Set Background
  fb.pen(rgba(0, 0, 0, 255)); // #000000
  fb.clear(); // Fill the screen with the current pen colour

  /**
   * Render Screen
   * TODO: Design rendering mechanish that allows the player to exist between
   * layers, without there being a fixed set of layers.
   */
  fb.sprites = overworld.tilesheet;
  draw_layer(overworld.currentMap->layers["background"]);
  draw_layer(overworld.currentMap->layers["tree_bottoms"]);
  draw_layer(overworld.currentMap->layers["tree_tops"]);
  draw_layer(overworld.currentMap->layers["objects"]);
}

void update(uint32_t current_time) {}


// Render Logic
point tile(const point &p) {
  return point(p.x / 8, p.y / 8);
}
void draw_layer(MapLayer &layer) {
  point tl = point(0, 0);
  point br = point(fb.bounds.w, fb.bounds.h);

  point tlt = tile(tl);
  point brt = tile(br);

  for (uint8_t y = tlt.y; y <= brt.y; y++) {
    for (uint8_t x = tlt.x; x <= brt.x; x++) {
      point pt = point(x * 8, y * 8);
      uint32_t ti = layer.map->tile_index(point(x, y));
      if (ti != (uint32_t)-1) {
        uint8_t si = layer.tiles[ti];
        if (si != 0) {
          fb.sprite((si - 1), pt);
        }
      }
    }
  }
}