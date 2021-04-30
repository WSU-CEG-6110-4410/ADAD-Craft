//  Req15Flower.hpp
//  TerrainBuilder Project req.15, 15.1, 15.2
//
//  Created by Haiyue Chen on 3/16/21.
//
#include <stdio.h>

#ifndef Req15Flower_hpp
#define Req15Flower_hpp

//the constant named BLOCK_01  would contain the value of 1
//This is one of the six types of block
#define BLOCK_01 1
//the constant named BLOCK_02  would contain the value of 2
//This is one of the six types of block
#define BLOCK_02 2
//the constant named BLOCK_03  would contain the value of 3
//This is one of the six types of block
#define BLOCK_03 3
//the constant named BLOCK_04  would contain the value of 4
//This is one of the six types of block
#define BLOCK_04 4
//the constant named BLOCK_05  would contain the value of 5
//This is one of the six types of block
#define BLOCK_05 5
//the constant named BLOCK_06  would contain the value of 6
//This is one of the six types of block
#define BLOCK_06 6
//the constant named YELLOW_FLOWER would contain the value of 7
//This is one of the six tpes of flower
#define YELLOW_FLOWER 7
//the constant named RED_FLOWER would contain the value of 8
//This is one of the six tpes of flower
#define RED_FLOWER 8
//the constant named PURPLE_FLOWER would contain the value of 9
//This is one of the six tpes of flower
#define PURPLE_FLOWER 9
//the constant named SUN_FLOWER would contain the value of 10
//This is one of the six tpes of flower
#define SUN_FLOWER 10
//the constant named WHITE_FLOWER would contain the value of 11
//This is one of the six tpes of flower
#define WHITE_FLOWER 11
//The constant named BLUE_FLOWER would contain the value of 12
//This is one of the six tpes of flower
#define BLUE_FLOWER 12
 
//items that user can build: blocks and flowers
extern const int items[];

/// \imp \ref R18 15.2six types of block
/// \param[in] flowers \imp \ref R18 req15.2  block types
extern const int blocks[6][6];

/// \imp \ref R17 15.2six types of flower
/// \param[in] flowers \imp \ref R17 req15.1 flower types
extern const int plants[6];

/// \imp \ref R17 15.1 six types of flower
/// \param[in] flowers \imp \ref R17 req15.1 flower types
///
void getFlowerType(int flowers, char type)

/// \imp \ref R16 15.paring a specific block with a specific flower
/// \param[in] blocks\imp \ref R18 req15.2 block types
/// \param[in] flowerss \imp \ref R17 req15.1 flower types
///
void paring(int blocks, int flowers);
 
#endif /* Req15Flower_hpp */
