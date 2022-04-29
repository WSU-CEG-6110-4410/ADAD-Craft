#include "config.h"
#include "noise.h"
#include "world.h"
#include "item.h"
#include <stdlib.h>


//! [issue] https://github.com/WSU-CEG-6110-4410/ADAD-Craft/issues/121
void create_world(int p, int q, world_func func, void *arg) {
    int pad = 1;
    for (int dx = -pad; dx < CHUNK_SIZE + pad; dx++) {
        for (int dz = -pad; dz < CHUNK_SIZE + pad; dz++) {
            int flag = 1;
            if (dx < 0 || dz < 0 || dx >= CHUNK_SIZE || dz >= CHUNK_SIZE) {
                flag = -1;
            }
            int x = p * CHUNK_SIZE + dx;
            int z = q * CHUNK_SIZE + dz;
            float f = simplex2(x * 0.01, z * 0.01, 4, 0.5, 2);
            float g = simplex2(-x * 0.01, -z * 0.01, 2, 0.9, 2);
            int mh = g * 32 + 16;
            int h = f * mh;
            int w = 1;
            int t = 12;
            if (h <= t) {
                h = t;
                w = 2;
            }
            // sand and grass terrain
            for (int y = 0; y < h; y++) {
                func(x, y, z, w * flag, arg);
            }
            if (w == 1) {
                if (SHOW_PLANTS) {
                    // GRASS GENERATION
                    if (simplex2(-x * 0.1, z * 0.1, 4, 0.8, 2) > 0.6) {
                        func(x, h, z, TALL_GRASS * flag, arg);
                    }

                    // FOLIAGE GENERATION
                    //  - Determine whether or not the block at (x,z) should contain foliage, and if so, determine the type
                    //  - A noise function is used to determine if the block should contain foliage
                    //  - Then, we assume the foliage type will be "YELLOW_FLOWER" aka the first foliage type present.
                    //  - Using a noise function, we create an offset by multiplying the result with the total number of foliage types
                    if (simplex2(x * 0.05, -z * 0.05, 4, 0.8, 2) > 0.7) {
                        int foliageType = YELLOW_FLOWER + simplex2(x * 0.1, z * 0.1, 4, 0.8, 2) * FOLIAGE_COUNT;
                        func(x, h, z, foliageType * flag, arg);
                    }
                }
                // trees
                int ok = SHOW_TREES;
                if (dx - 4 < 0 || dz - 4 < 0 ||
                    dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
                {
                    ok = 0;
                }

                // TREE GENERATION
                // - Generate leaves
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

                    // - Generate trunk
                    // - To add future types of trees, I recommend moving around the block IDs so that they fall directly in a range (like 5-7 for 3 tree types)
                    // - Doing so would allow you to refactor the code into a single for loop where you set "tree_type" to be what block is generated
                    int tree_type = (rand() % (TREE_TYPES)) + 1; 

                    if (tree_type == 1) {
                      for (int y = h; y < h + 7; y++) {
                        func(x, y, z, WOOD, arg);
                      }
                    }
                    else {
                      for (int y = h; y < h + 7; y++) {
                        func(x, y, z, BIRCH_WOOD, arg);
                      }
                    }

                }
            }
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
