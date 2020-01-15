#include "rpg.hpp"

#include "map.hpp"

using namespace blit;

// Instantiate BlitRPG::Map class instance
BlitRPG::Map overworld = BlitRPG::Map();

// Create Blit Map.
Map map(rect(0, 0, overworld.tile_width, overworld.tile_height));

spritesheet *tiles;

void init() {
  std::vector<uint8_t> layer_background = {
    227, 228, 227, 228, 227, 228, 227, 228, 209, 210, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 243, 227, 227, 228, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 227, 243, 243, 227, 227, 227, 228, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 195, 196, 243, 244, 243, 243, 243, 227, 227, 227, 228, 244, 243, 244, 243, 244, 243, 244, 243, 244, 211, 212, 227, 228, 227, 228, 225, 226, 193, 194, 227, 227, 228, 228, 227, 228, 227, 228, 227, 228, 227, 228, 243, 225, 226, 244, 241, 242, 209, 210, 243, 227, 227, 227, 228, 195, 196, 244, 243, 244, 243, 244, 227, 241, 242, 228, 227, 228, 227, 228, 227, 243, 243, 227, 227, 211, 212, 228, 227, 228, 227, 228, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 243, 243, 227, 227, 228, 243, 244, 243, 244, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 243, 243, 227, 228, 228, 227, 228, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 227, 227, 228, 243, 244, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 243, 227, 228, 227, 228, 196, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 227, 227, 228, 244, 212, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 243, 227, 228, 228, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 243, 244, 195, 196, 243, 227, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 227, 228, 211, 212, 227, 243, 243, 244
  };
  map.add_layer("background", layer_background);

  tiles = spritesheet::load(environment_data);
}

void render(uint32_t time_ms) {
  // Set Background
  fb.pen(rgba(0, 0, 0, 255)); // #000000
  fb.clear(); // Fill the screen with the current pen colour



  // Render Screen
  fb.sprites = tiles;
  draw_layer(map.layers["background"]);


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