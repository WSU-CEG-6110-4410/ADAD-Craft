//
//  Req14Speed.hpp
//  TerrainBuilder Project req.14
//
//  Created by HaiyueChen on 4/12/21.
//
#include <stdio.h>
#ifndef Req14Speed_hpp
#define Req14Speed_hpp
 
/// \imp \ref R15 the constant named BLOCK_01  would contain the value of 1
/// This is one of the six types of block
#define BLOCK_01 1
/// \imp \ref R15 the constant named BLOCK_02  would contain the value of 2
/// This is one of the six types of block
#define BLOCK_02 2
/// \imp \ref R15 the constant named BLOCK_03  would contain the value of 3
/// This is one of the six types of block
#define BLOCK_03 3
/// \imp \ref R15 the constant named BLOCK_04  would contain the value of 4
/// This is one of the six types of block
#define BLOCK_04 4
/// \imp \ref R15 the constant named BLOCK_05  would contain the value of 5
/// This is one of the six types of block
#define BLOCK_05 5
/// \imp \ref R15 the constant named BLOCK_06  would contain the value of 6
/// This is one of the six types of block
#define BLOCK_06 6

/// Ref: R14 req14 For different types of block, adjust the user speed.
/// Six types of block in this case.
/// \imp \ref R14
///
/// \imp \ref R15
/// \param[in] type \imp \ref R15 req15.1 the type of block
///
void set_Block_Type(int type){blockType = type;}

/// \imp \ref R15
///
int get_Block_Type(){return blockType;}

/// \imp \ref R14  Decide UserSpeed according to block_type
/// \param[in] blocktypes \imp \ref R15 req14.1 the type of block
/// \param[in] speed \imp \ref R14 req15 adjust the user speed based on blocktype
void set_User_Speed(blocktype, int speed)

#endif /* Req14Speed_hpp */
