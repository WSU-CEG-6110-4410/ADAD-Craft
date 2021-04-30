#include "config.h"
#include "noise.h"
#include "world.h"
#include "util.h"

//TerrainBuilder Project Req. 3, 4, 6, 7
//Modifications by Alex Gentry

int spawn_plants(double freq, int index, int num, int x, int z){
	int w = index + simplex2(x * 0.1, z * 0.1, 4, freq, 2) * num;
	return w;
}

void create_world(int p, int q, world_func func, void *arg) {
    int pad = 1;
    for (int dx = -pad; dx < CHUNK_SIZE + pad; dx++) {
        for (int dz = -pad; dz < CHUNK_SIZE + pad; dz++) {
            int flag = 1;
            if (dx < 0 || dz < 0 || dx >= CHUNK_SIZE || dz >= CHUNK_SIZE) {
                flag = -1;
            }
			/// \imp \ref R3 Creates unique surface blocks per biome.
			/// \imp \ref R6 Changes underground blocks to not have grass or snow on top.
			/// \imp \ref R7 Creates veins of ore throughout the underground.

			//---Requirement 3, 6, 7---
			// Generates unique surface blocks per biome.
			// Generates consistent underground dirt and sand blocks.
			// Generates veins of ore/fossils spread out underground.
            int x = p * CHUNK_SIZE + dx;
            int z = q * CHUNK_SIZE + dz;
            float f = simplex2(x * 0.01, z * 0.01, 4, 0.5, 2);
            float g = simplex2(-x * 0.01, -z * 0.01, 2, 0.9, 2);
			/// \imp \ref R5 Generates forest biomes of adequate average size
			float b = simplex2(x * 0.01, -z * 0.01, 2, 0.9, 2);
            int mh = g * 32 + 16;
            int h = f * mh;
            int w = 1;
            int t = 12;
			int tc = 25;
			if (b >= 0.66) {
				w = 74;
			}
            if (h <= t) {
                h = t;
                w = 2;
            }
			if (h > tc) {
				w = 9;
			}
			/// \imp \ref R2 Creates biomes for mountain tops and forests
            // terrain 
            for (int y = 0; y < h; y++) {
				int u = w;
				if (y < h - 1){
					if (simplex3(
                        x * 0.01, y * 0.1, z * 0.01, 8, 0.5, 2) > 0.8) {
						u = 78 + simplex2(x * 0.1, z * 0.1, 4, 0.8, 2) * 5;
					}
					switch(u) {
						case 1:
						case 9:
							u = 7;
							break;
						case 74:
							u = 83;
							break;
					}
				}
               	func(x, y, z, u * flag, arg);
            }
			/// \imp \ref R4 Populates biomes with appropriate plants

			//-------------------
			//---Requirement 4---
			if (w == 2) {
				if (SHOW_PLANTS) {
					// desert plants
					if (simplex2(-x * 0.1, z * 0.1, 3, 0.8, 2) > 0.8) {
						int w = spawn_plants(0.2, 64, 3, x, z);
						func(x, h, z, w * flag, arg);
					}
				}
				// desert 'trees'
				int ok = SHOW_TREES;
				if (ok && simplex2(x, z, 6, 0.5, 2) > 0.87) {
                    for (int y = h; y < h + 3; y++) {
                        func(x, y, z, 75, arg);
                    }
                }
			}
			if (w == 9) {
				if (SHOW_PLANTS) {
					// tundra plants
					if (simplex2(-x * 0.1, z * 0.1, 3, 0.8, 2) > 0.7) {
						int w = spawn_plants(0.3, 67, 3, x, z);
						func(x, h, z, w * flag, arg);
					}
				}
				// tundra trees
				int ok = SHOW_TREES;
				if (dx - 4 < 0 || dz - 4 < 0 ||
                    dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
                {
                    ok = 0;
                }
				if (ok && simplex2(x, z, 6, 0.5, 2) > 0.84) {
                    for (int y = h + 2; y < h + 8; y++) {
                        for (int ox = -4; ox <= 4; ox++) {
                            for (int oz = -4; oz <= 4; oz++) {
								int d = ((ABS(ox) + ABS(oz))) + (y - (h + 2));
								if (d <= 5) {
                            		func(x + ox, y, z + oz, 85, arg);
								}
                            }
                        }
                    }
                    for (int y = h; y < h + 7; y++) {
                        func(x, y, z, 76, arg);
                    }
                }
			}
			if (w == 74){
				if (SHOW_PLANTS) {
					// jungle plants
					if (simplex2(-x * 0.1, z * 0.1, 3, 0.8, 2) > 0.7) {
						int w = spawn_plants(0.1, 70, 3, x, z);
						func(x, h, z, w * flag, arg);
					}
				}
				// jungle trees
				int ok = SHOW_TREES;
				if (dx - 4 < 0 || dz - 4 < 0 ||
                    dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
                {
                    ok = 0;
                }
				if (ok && simplex2(x, z, 6, 0.5, 2) > 0.8) {
                    for (int y = h + 3; y < h + 8; y++) {
                        for (int ox = -3; ox <= 3; ox++) {
                            for (int oz = -3; oz <= 3; oz++) {
                                int d = (ox * ox) + (oz * oz) +
                                    (y - (h + 4)) * (y - (h + 4));
                                if (d < 11) {
                                    func(x + ox, y, z + oz, 84, arg);
                                }
                            }
                        }
                    }
                    for (int y = h; y < h + 7; y++) {
                        func(x, y, z, 77, arg);
                    }
                }
			}
            if (w == 1) {
                if (SHOW_PLANTS) {
                    // grass
                    if (simplex2(-x * 0.1, z * 0.1, 4, 0.8, 2) > 0.6) {
                        func(x, h, z, 17 * flag, arg);
                    }
                    // flowers
                    if (simplex2(x * 0.05, -z * 0.05, 4, 0.8, 2) > 0.7) {
						int w = spawn_plants(0.8, 18, 7, x, z);
                        func(x, h, z, w * flag, arg);
                    }
                }
                // trees
                int ok = SHOW_TREES;
                if (dx - 4 < 0 || dz - 4 < 0 ||
                    dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
                {
                    ok = 0;
                }
                if (ok && simplex2(x, z, 6, 0.5, 2) > 0.84) {
                    for (int y = h + 3; y < h + 8; y++) {
                        for (int ox = -3; ox <= 3; ox++) {
                            for (int oz = -3; oz <= 3; oz++) {
                                int d = (ox * ox) + (oz * oz) +
                                    (y - (h + 4)) * (y - (h + 4));
                                if (d < 11) {
                                    func(x + ox, y, z + oz, 15, arg);
                                }
                            }
                        }
                    }
                    for (int y = h; y < h + 7; y++) {
                        func(x, y, z, 5, arg);
                    }
                }
            }
			//-------------------
            // clouds
            if (SHOW_CLOUDS) {
                for (int y = 64; y < 72; y++) {
                    if (simplex3(
                        x * 0.01, y * 0.1, z * 0.01, 8, 0.5, 2) > 0.75)
                    {
                        func(x, y, z, 16 * flag, arg);
                    }
                }
            }
        }
    }
}

