//
//  Test for req.14,15
//
//  Created by HaiyueChen on 4/18/21.
//
#include <gtest/gtest.h>
#include "Req15Flower.hpp"
#include "Req14Speed.hpp"
 

///Ref: Req.14,15
///
///  \imp \ref R16 Test for req.15 paring a specific block with a specific flower
/// \param[in] blocks\imp \ref R18 req15.2 block types
/// \param[in] flowerss \imp \ref R17 req15.1 flower types
//Test: When block type = 1,flower type = 7.
Test(Req15Flower, paringBlock01) {
    int blocks =1;
    EXPECT_EQ(int flowers = 7, paring(1,7));
}
///
///  \imp \ref R16 Test for req.15 paring a specific block with a specific flower
/// \param[in] blocks\imp \ref R18 req15.2 block types
/// \param[in] flowerss \imp \ref R17 req15.1 flower types
//Test: When block type = 2,flower type = 8.
Test(Req15Flower, paringBlock02) {
    int blocks =2;
    EXPECT_EQ(int flowers = 8, paring(2,8));
}
///
///  \imp \ref R16 Test for req.15 paring a specific block with a specific flower
/// \param[in] blocks\imp \ref R18 req15.2 block types
/// \param[in] flowerss \imp \ref R17 req15.1 flower types
//Test: When block type = 3,flower type = 9.
Test(Req15Flower, paringBlock03) {
    int blocks =3;
    EXPECT_EQ(int flowers = 9, paring(3,9));
}
///
///  \imp \ref R16 Test for req.15 paring a specific block with a specific flower
/// \param[in] blocks\imp \ref R18 req15.2 block types
/// \param[in] flowerss \imp \ref R17 req15.1 flower types
//Test: When block type = 4,flower type = 10.
Test(Req15Flower, paringBlock04) {
    int blocks =4;
    EXPECT_EQ(int flowers = 10, paring(4,10));
}
///
///  \imp \ref R16 Test for req.15 paring a specific block with a specific flower
/// \param[in] blocks\imp \ref R18 req15.2 block types
/// \param[in] flowerss \imp \ref R17 req15.1 flower types
//Test: When block type = 5,flower type = 11.
Test(Req15Flower, paringBlock05) {
    int blocks =5;
    EXPECT_EQ(int flowers = 11, paring(5,11));
}
///
///  \imp \ref R16 Test for req.15 paring a specific block with a specific flower
/// \param[in] blocks\imp \ref R18 req15.2 block types
/// \param[in] flowerss \imp \ref R17 req15.1 flower types
//Test: When block type = 6,flower type = 12.
Test(Req15Flower, paringBlock06) {
    int blocks =6;
    EXPECT_EQ(int flowers = 12, paring(6,12));
}
///
/// \imp \ref R14 Test for req14  Decide UserSpeed according to block_type
/// req14 adjust the user speed based on blocktype
//Test: When BLOCK_01, user speed =3
Test(Req14Speed, setUserSpeed01) {
    EXPECT_EQ(case BLOCK_01, set_User_Speed(BLOCK_01,3));
}
///
/// \imp \ref R14 Test for req14  Decide UserSpeed according to block_type
/// req14 adjust the user speed based on blocktype
//Test: When BLOCK_02, user speed =6
Test(Req14Speed, setUserSpeed02) {
    EXPECT_EQ(case BLOCK_02, set_User_Speed(BLOCK_02,6));
}
///
/// \imp \ref R14 Test for req14  Decide UserSpeed according to block_type
/// req14 adjust the user speed based on blocktype
//Test: When BLOCK_03, user speed =9
Test(Req14Speed, setUserSpeed03) {
    EXPECT_EQ(case BLOCK_03, set_User_Speed(BLOCK_03,9));
}
///
/// \imp \ref R14 Test for req14  Decide UserSpeed according to block_type
/// req14 adjust the user speed based on blocktype
//Test: When BLOCK_04, user speed =12
Test(Req14Speed, setUserSpeed04) {
    EXPECT_EQ(case BLOCK_04, set_User_Speed(BLOCK_04,12));
}
///
/// \imp \ref R14 Test for req14  Decide UserSpeed according to block_type
/// req14 adjust the user speed based on blocktype
//Test: When BLOCK_05, user speed =15
Test(Req14Speed, setUserSpeed05) {
    EXPECT_EQ(case BLOCK_05, set_User_Speed(BLOCK_05,15));
}
///
/// \imp \ref R14 Test for req14  Decide UserSpeed according to block_type
/// req14 adjust the user speed based on blocktype
//Test: When BLOCK_06, user speed =18
Test(Req14Speed, setUserSpeed06) {
    EXPECT_EQ(case BLOCK_06, set_User_Speed(BLOCK_06,18));
}

