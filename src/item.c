#include "item.h"
#include "util.h"

const int items[] = {
	/// \imp \ref R3 Adds new terrain to crafting options
	/// \imp \ref R4 Adds new plants to crafting options
	/// \imp \ref R7 Adds underground blocks to crafting options 
	/// \imp \ref R23 Adds tree and leaf blocks to crafting options

    // items the user can build
    GRASS,
	DIRT,
    FOREST,
	FOREST_DIRT,
    SAND,
    SANDSTONE,
    STONE,
    BRICK,
    WOOD,
    DEAD_WOOD,
    DARK_WOOD,
    LIGHT_WOOD,
    CEMENT,
    PLANK,
    SNOW,
    GLASS,
    COBBLE,
    LIGHT_STONE,
    DARK_STONE,
	IRON_ORE,
	COPPER_ORE,
	COBALT_ORE,
	GOLD_ORE,
	FOSSIL,
    CHEST,
    LEAVES,
    TALL_GRASS,
    YELLOW_FLOWER,
    RED_FLOWER,
    PURPLE_FLOWER,
    SUN_FLOWER,
    WHITE_FLOWER,
    BLUE_FLOWER,
    ROUND_CACTUS,
    WING_CACTUS,
    DESERT_GRASS,
    PUFF_FLOWER,
    TUNDRA_GRASS,
    HOLLY_BUSH,
    MONSTERA,
    POISON_FLOWER,
    SNAKE_PLANT,
    COLOR_00,
    COLOR_01,
    COLOR_02,
    COLOR_03,
    COLOR_04,
    COLOR_05,
    COLOR_06,
    COLOR_07,
    COLOR_08,
    COLOR_09,
    COLOR_10,
    COLOR_11,
    COLOR_12,
    COLOR_13,
    COLOR_14,
    COLOR_15,
    COLOR_16,
    COLOR_17,
    COLOR_18,
    COLOR_19,
    COLOR_20,
    COLOR_21,
    COLOR_22,
    COLOR_23,
    COLOR_24,
    COLOR_25,
    COLOR_26,
    COLOR_27,
    COLOR_28,
    COLOR_29,
    COLOR_30,
    COLOR_31
};

const int item_count = sizeof(items) / sizeof(int);

const int blocks[256][6] = {
    // w => (left, right, top, bottom, front, back) tiles
    {0, 0, 0, 0, 0, 0}, // 0 - empty
    {16, 16, 32, 0, 16, 16}, // 1 - grass
    {1, 1, 1, 1, 1, 1}, // 2 - sand
    {2, 2, 2, 2, 2, 2}, // 3 - stone
    {3, 3, 3, 3, 3, 3}, // 4 - brick
    {20, 20, 36, 4, 20, 20}, // 5 - wood
    {5, 5, 5, 5, 5, 5}, // 6 - cement
    {6, 6, 6, 6, 6, 6}, // 7 - dirt
    {7, 7, 7, 7, 7, 7}, // 8 - plank
    {24, 24, 40, 8, 24, 24}, // 9 - snow
    {9, 9, 9, 9, 9, 9}, // 10 - glass
    {10, 10, 10, 10, 10, 10}, // 11 - cobble
    {11, 11, 11, 11, 11, 11}, // 12 - light stone
    {12, 12, 12, 12, 12, 12}, // 13 - dark stone
    {13, 13, 13, 13, 13, 13}, // 14 - chest
    {14, 14, 14, 14, 14, 14}, // 15 - leaves
    {15, 15, 15, 15, 15, 15}, // 16 - cloud
    {0, 0, 0, 0, 0, 0}, // 17
    {0, 0, 0, 0, 0, 0}, // 18
    {0, 0, 0, 0, 0, 0}, // 19
    {0, 0, 0, 0, 0, 0}, // 20
    {0, 0, 0, 0, 0, 0}, // 21
    {0, 0, 0, 0, 0, 0}, // 22
    {0, 0, 0, 0, 0, 0}, // 23
    {0, 0, 0, 0, 0, 0}, // 24
    {0, 0, 0, 0, 0, 0}, // 25
    {0, 0, 0, 0, 0, 0}, // 26
    {0, 0, 0, 0, 0, 0}, // 27
    {0, 0, 0, 0, 0, 0}, // 28
    {0, 0, 0, 0, 0, 0}, // 29
    {0, 0, 0, 0, 0, 0}, // 30
    {0, 0, 0, 0, 0, 0}, // 31
    {176, 176, 176, 176, 176, 176}, // 32
    {177, 177, 177, 177, 177, 177}, // 33
    {178, 178, 178, 178, 178, 178}, // 34
    {179, 179, 179, 179, 179, 179}, // 35
    {180, 180, 180, 180, 180, 180}, // 36
    {181, 181, 181, 181, 181, 181}, // 37
    {182, 182, 182, 182, 182, 182}, // 38
    {183, 183, 183, 183, 183, 183}, // 39
    {184, 184, 184, 184, 184, 184}, // 40
    {185, 185, 185, 185, 185, 185}, // 41
    {186, 186, 186, 186, 186, 186}, // 42
    {187, 187, 187, 187, 187, 187}, // 43
    {188, 188, 188, 188, 188, 188}, // 44
    {189, 189, 189, 189, 189, 189}, // 45
    {190, 190, 190, 190, 190, 190}, // 46
    {191, 191, 191, 191, 191, 191}, // 47
    {192, 192, 192, 192, 192, 192}, // 48
    {193, 193, 193, 193, 193, 193}, // 49
    {194, 194, 194, 194, 194, 194}, // 50
    {195, 195, 195, 195, 195, 195}, // 51
    {196, 196, 196, 196, 196, 196}, // 52
    {197, 197, 197, 197, 197, 197}, // 53
    {198, 198, 198, 198, 198, 198}, // 54
    {199, 199, 199, 199, 199, 199}, // 55
    {200, 200, 200, 200, 200, 200}, // 56
    {201, 201, 201, 201, 201, 201}, // 57
    {202, 202, 202, 202, 202, 202}, // 58
    {203, 203, 203, 203, 203, 203}, // 59
    {204, 204, 204, 204, 204, 204}, // 60
    {205, 205, 205, 205, 205, 205}, // 61
    {206, 206, 206, 206, 206, 206}, // 62
    {207, 207, 207, 207, 207, 207}, // 63
    {0, 0, 0, 0, 0, 0}, // 64
    {0, 0, 0, 0, 0, 0}, // 65
    {0, 0, 0, 0, 0, 0}, // 66
    {0, 0, 0, 0, 0, 0}, // 67
    {0, 0, 0, 0, 0, 0}, // 68
    {0, 0, 0, 0, 0, 0}, // 69
    {0, 0, 0, 0, 0, 0}, // 70
    {0, 0, 0, 0, 0, 0}, // 71
    {0, 0, 0, 0, 0, 0}, // 72
	/// \imp \ref R3 Builds terrain block textures
    //---Requirement 3---
    {17, 17, 17, 17, 17, 17}, // 73 - sandstone
    {25, 25, 41, 0, 25, 25}, // 74 - forest
	/// \imp \ref R23 Builds tree block textures
    {21, 21, 37, 37, 21, 21}, // 75 - dead wood
    {22, 22, 38, 38, 22, 22}, // 76 - dark wood
    {23, 23, 39, 39, 23, 23}, // 77 - light wood
	/// \imp \ref R7 Builds underground block textures
    //---Requirement 7---
	{33, 33, 5, 5, 33, 33}, // 78 - iron ore
	{34, 34, 5, 5, 34, 34}, // 79 - copper ore
	{35, 35, 5, 5, 35, 35}, // 80 - fossil
	{18, 18, 5, 5, 18, 18}, // 81 - gold ore
	{19, 19, 5, 5, 19, 19}, // 82 - cobalt ore
	{26, 26, 26, 26, 26, 26}, // 83 - forest dirt
	/// \imp \ref R23 Builds leaf block textures
	{42, 42, 42, 42, 42, 42}, // 84 - dark leaves
	{42, 42, 40, 42, 42, 42}, // 85 - snow leaves
};

const int plants[256] = {
    // w => tile
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0 - 16
    48, // 17 - tall grass
    49, // 18 - yellow flower
    50, // 19 - red flower
    51, // 20 - purple flower
    52, // 21 - sun flower
    53, // 22 - white flower
    54, // 23 - blue flower
	/// \imp \ref R4 Adds new plants to plant array
    //---Requirement 4---
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 24 - 40
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 41 - 57
    0, 0, 0, 0, 0, 0, // 58 - 60
    //Desert:
    55, // 64 - round cactus
    56, // 65 - wing cactus
    57, // 66 - desert grass
    //Tundra:
    58, // 67 - puff flower
    59, // 68 - tundra grass
    60, // 69 - holly bush
    //Jungle:
    61, // 70 - monstera
    62, // 71 - poison flower
    63, // 72 - snake plant
};

int is_plant(int w) {
    switch (w) {
        case TALL_GRASS:
        case YELLOW_FLOWER:
        case RED_FLOWER:
        case PURPLE_FLOWER:
        case SUN_FLOWER:
        case WHITE_FLOWER:
        case BLUE_FLOWER:
		case ROUND_CACTUS:
		case WING_CACTUS:
		case DESERT_GRASS:
		case PUFF_FLOWER:
		case TUNDRA_GRASS:
		case HOLLY_BUSH:
		case MONSTERA:
		case POISON_FLOWER:
		case SNAKE_PLANT:
            return 1;
        default:
            return 0;
    }
}

int is_obstacle(int w) {
    w = ABS(w);
    if (is_plant(w)) {
        return 0;
    }
    switch (w) {
        case EMPTY:
        case CLOUD:
            return 0;
        default:
            return 1;
    }
}

int is_transparent(int w) {
    if (w == EMPTY) {
        return 1;
    }
    w = ABS(w);
    if (is_plant(w)) {
        return 1;
    }
    switch (w) {
        case EMPTY:
        case GLASS:
        case LEAVES:
		/// \imp \ref R23 Adds new leaves as transparent blocks
		case DARK_LEAVES:
		case SNOW_LEAVES:
            return 1;
        default:
            return 0;
    }
}

int is_destructable(int w) {
    switch (w) {
        case EMPTY:
        case CLOUD:
            return 0;
        default:
            return 1;
    }
}
