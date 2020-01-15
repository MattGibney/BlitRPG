#include "rpg.hpp"

#include "map.hpp"

using namespace blit;

/**
 * Instantiate BlitRPG::Map class instance. This should be called with the required data.
 * 
 * Perhaps JSON?
 */
BlitRPG::Map overworld = BlitRPG::Map();

// Create Blit Map.
Map *currentMap;

spritesheet *tiles;

void init() {
  
  currentMap = new Map(rect(0, 0, overworld.tile_width, overworld.tile_height));
  
  currentMap->add_layer("background", overworld.layers[0]);

  tiles = spritesheet::load(environment_data);
}

void render(uint32_t time_ms) {
  // Set Background
  fb.pen(rgba(0, 0, 0, 255)); // #000000
  fb.clear(); // Fill the screen with the current pen colour



  /**
   * Render Screen
   * Rendering logic should be kept very separate from the game logic. Therefore, the below code will take in the BlitRPG::Map object as a param.
   */
  fb.sprites = tiles;
  draw_layer(currentMap->layers["background"]);


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