//Terrain Builder
//Created by Jonathan Morelock 3/12/2021

#ifndef _Requirements10_11_12_19_h_
#define _Requirements10_11_12_19_h_

/**
 * \defgroup Terrain Jonathan_Terrain_Mods
 * @{
 * The modifications of the "Craft" game terrain generation.
 **/

///Ref: Req. 19 using enum types to set various inclimate weather conditions in the world.
///
/// \imp \ref R22
///
typedef enum
{
    RAIN,
    SNOWY,
    CLEAR
} PrecipTypes;

/// Ref: Req. 19 Using x y and z vectors for setting the location of precipitation in the world.
///
/// \imp \ref R22
///
typedef struct
{
    float x;
    float y;
    float z;
} PrecipitationVectors;

/// Ref: R10 R11 R12 Req. 10 & 19 Using render_radius for Req. 10 to adjust the draw distance during inclimate
/// weather. Using area as a size (in chunks) to create precipitation in the world.
///
/// \imp \ref R10
/// \imp \ref R11
/// \imp \ref R12
/// \imp \ref R22
///
typedef struct
{
    PrecipTypes type;
    PrecipitationVectors pv;
} Precipitation;

/// Ref: R10 R11 R12 Req. 10, 11, 12  Using speed (set in main.c "handle_movement" function at line 2441) adjusts the
/// render_radius based on the speed the user is moving and the weather conditions present. 
/// (set in main.c line 2715 & modified based on chunk size on line 1628).
///
/// \imp \ref R10
/// \imp \ref R11
/// \imp \ref R12
///
/// \param[in] speed Req. 11 & 12 the speed the player is moving.
/// \param[in] render_radius Req. 11 & 12 the radius of the terrain to be rendered around player.
/// \param[in] P Req. 10 the weather conditions used for limiting the draw distance
///
int set_draw_distance(int render_radius, float speed, Precipitation * P);

///\param[in] render_radius the radius around the user to render precipitation.
///\param[in] precip_type the type of precipitation to be rendered 0 for rain, 1 for snow, 2 for clear.
///
/// \imp \ref R10
/// \imp \ref R22
///
void render_precipitation(int render_radius, int precip_type);

///\param[in] x Req. 19 the x vector the precipitation will be traversing while it falls.
///\param[in] y Req. 19 the y vector the precipitation will be traversing while it falls.
///\param[in] z Req. 19 the z vector the precipitation will be traversing while it falls.
///
/// \imp \ref R22
///
void generate_precipitation_vectors(Precipitation *P, float x, float y, float z);

/// \param[in] precip_type Req. 19 the type of precipitation to be rendered 0 for rain, 1 for snow.
/// \param[in] P Req. 19 the precipitation struct to pass precip_type into.
///
/// \imp \ref R22
///
void set_precipitation_type(Precipitation *P, int precip_type);

/**@}*/
#endif /* Requirements10_11_12_19_h */