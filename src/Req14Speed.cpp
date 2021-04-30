//
//  Req14Speed.cpp
//  TerrainBuilder Project req.14
//
//  Created by HaiyueChen on 4/12/21.
//

#include "Req14Speed.hpp"
 
void set_Block_Type(int type){blockType = type;}

int get_Block_Type(){return blockType;}
 
void set_User_Speed(blocktype, int speed){
    switch(blocktype){
        case BLOCK_01:
            speed = 3;
            break;
        case BLOCK_02:
            speed = 6;
            break;
        case BLOCK_03:
            speed = 9;
            break;
        case BLOCK_04:
            speed = 12;
            break;
        case BLOCK_05:
            speed = 15;
            break;
        case BLOCK_06:
            speed = 18;
        break;
    }
}
