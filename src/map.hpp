namespace BlitRPG {
  class RPGMap{
    public:
      int tile_width;
      int tile_height;
      std::vector<uint8_t> layers[4];
      
      // Create Blit Map.
      Map *currentMap;

      // Constructor
      RPGMap() {}
  };
};
