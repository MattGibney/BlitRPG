#pragma once

#include "32blit.hpp"

void init();
void render(uint32_t time);
void update(uint32_t time);

point tile(const point &p);
void draw_layer(MapLayer &layer);
