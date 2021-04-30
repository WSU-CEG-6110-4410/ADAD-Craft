//
//  Req15Flower.cpp
//  TerrainBuilder Project req.15, 15.1, 15.2
//
//  Created by Haiyue Chen on 3/16/21.
//

#include "Req15Flower.hpp"
const int items[] = {
    // items the user can build
    BLOCK_01;
    BLOCK_02;
    BLOCK_03;
    BLOCK_04;
    BLOCK_05;
    BLOCK_06;
    YELLOW_FLOWER,
    RED_FLOWER,
    PURPLE_FLOWER,
    SUN_FLOWER,
    WHITE_FLOWER,
    BLUE_FLOWER
};
//refer to item.c line64
const int blocks[6][6] = {
    // w => (left, right, top, bottom, front, back) tiles
    {1, 1, 1, 1, 1, 1}, //BLOCK_01
    {2, 2, 2, 2, 2, 2}, //BLOCK_02
    {3, 3, 3, 3, 3, 3}, //BLOCK_03
    {4, 4, 4, 4, 4, 4,} //BLOCK_04
    {5, 5, 5, 5, 5, 5}, //BLOCL_05
    {6, 6, 6, 6, 6, 6}, //BLOCK_06
};
//refer to item.c line132
const int flowers[6] = {
    // w => tile
    7, // 6- yellow flower
    8, // 7 - red flower
    9, // 8- purple flower
    10, // 9 - sun flower
    11, // 10 - white flower
    12, // 11- blue flower
};

void getFlowerType(int flowers, char type){
    if(flowers = 7)
        type = YELLOW_FLOWER;
    else if (flowers = 8)
        type = RED_FLOWER;
    else if (flowers = 9)
        type = PURPLE_FLOWER;
    else if (flowers = 10)
        type = SUN_FLOWER;
    else if (flowers = 11)
        type = WHITE_FLOWER;
    else if (flowers = 12)
        type = BLUE_FLOWER;
    
}
//paring a specific block with a specific flower
void paring(int blocks, int flowers)
{
    switch (blocks) {
        case 1: //BLOCK_01
            flowers = 7;
            getFlowerType();//get yellow flower
            break;
        case 2: //BLOCK_02
            flowers = 8;
            getFlowerType();//get red flower
            break;
        case 3: //BLOCK_03
            flowers = 9;
            getFlowerType();//get purple flower
            break;
        case 4: //BLOCK_04
            flowers = 10;
            getFlowerType();//get sun flowe
            break;
        case 5: //BLOCL_05
            flowers = 11;
            getFlowerType();//get white flower
            break;
        case 6: //BLOCK_06
            flowers = 12;
            getFlowerType();//get blue flowers
            break;
        default:
            
    }
}



 

