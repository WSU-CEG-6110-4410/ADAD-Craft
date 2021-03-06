# This Is My CEG-4110 Spring 2020 Project

**by Erik M. Buck**

## Craft

Minecraft clone for Windows, Mac OS X and Linux. Just a few thousand lines of C using modern OpenGL (shaders). Online multiplayer support is included using a Python-based server.

http://www.michaelfogleman.com/craft/

![Screenshot](http://i.imgur.com/SH7wcas.png)

### Features

- Simple but nice looking terrain generation using perlin / simplex noise.
- More than 10 types of blocks and more can be added easily.
- Supports plants (grass, flowers, trees, etc.) and transparency (glass).
- Simple clouds in the sky (they don't move).
- Day / night cycles and a textured sky dome.
- World changes persisted in a sqlite3 database.
- Multiplayer support!

### Download

Mac and Windows binaries are available on the website.

http://www.michaelfogleman.com/craft/

See below to run from source.

### Install Dependencies

#### Mac OS X

Download and install [CMake](http://www.cmake.org/cmake/resources/software.html)
if you don't already have it. You may use [Homebrew](http://brew.sh) to simplify
the installation:

    brew install cmake

#### Linux (Ubuntu)

    sudo apt-get install cmake libglew-dev xorg-dev libcurl4-openssl-dev
    sudo apt-get build-dep glfw

#### Windows

Download and install [CMake](http://www.cmake.org/cmake/resources/software.html)
and [MinGW](http://www.mingw.org/). Add `C:\MinGW\bin` to your `PATH`.

Download and install [cURL](http://curl.haxx.se/download.html) so that
CURL/lib and CURL/include are in your Program Files directory.

Use the following commands in place of the ones described in the next section.

    cmake -G "MinGW Makefiles"
    mingw32-make

### Compile and Run

Once you have the dependencies (see above), run the following commands in your
terminal.

    git clone https://github.com/fogleman/Craft.git
    cd Craft
    cmake .
    make
    ./craft

### Multiplayer

Register for an account!

https://craft.michaelfogleman.com/

#### Client

You can connect to a server with command line arguments...

    ./craft craft.michaelfogleman.com

Or, with the "/online" command in the game itself.

    /online craft.michaelfogleman.com

#### Server

You can run your own server or connect to mine. The server is written in Python
but requires a compiled DLL so it can perform the terrain generation just like
the client.

    gcc -std=c99 -O3 -fPIC -shared -o world -I src -I deps/noise deps/noise/noise.c src/world.c
    python server.py [HOST [PORT]]

### Controls

- WASD to move forward, left, backward, right.
- Space to jump.
- Hold Left Alt key to move around twice as fast
- Left Click to destroy a block.
- Right Click or Cmd + Left Click to create a block.
- Ctrl + Right Click to toggle a block as a light source.
- 1-9 to select the block type to create.
- E to cycle through the block types.
- Tab to toggle between walking and flying.
- ZXCVBN to move in exact directions along the XYZ axes.
- Left shift to zoom.
- F to show the scene in orthographic mode.
- O to observe players in the main view.
- P to observe players in the picture-in-picture view.
- T to type text into chat.
- Forward slash (/) to enter a command.
- Backquote (`) to write text on any block (signs).
- Arrow keys emulate mouse movement.
- Enter emulates mouse click.
- Q to quit the game.
- M to terminate the game and terminal without saving.

### Chat Commands

    /goto [NAME]

Teleport to another user.
If NAME is unspecified, a random user is chosen.

    /list

Display a list of connected users.

    /login NAME

Switch to another registered username.
The login server will be re-contacted. The username is case-sensitive.

    /logout

Unauthenticate and become a guest user.
Automatic logins will not occur again until the /login command is re-issued.

    /offline [FILE]

Switch to offline mode.
FILE specifies the save file to use and defaults to "craft".

    /online HOST [PORT]

Connect to the specified server.

    /pq P Q

Teleport to the specified chunk.

    /spawn

Teleport back to the spawn point.

```
/random
```

Gives you a random block.
```
/teleport [X] [Y] [Z]
```
Teleport using the specified coordinates.
```
/portx [X]
```
Teleport using the specified x-coordinate.
```
/porty [Y]
```
Teleport using the specified y-coordinate.
```
/portz [Z]
```
Teleport using the specified z-coordinate.
```
/dawn
```
Set the time of day to morning.
```
/dusk
```
Set the time of day to night.

### Block Commands

You can select a block through the command line. Just type in the number that corresponds to the block you wish to use.

- 0- grass
- 1- sand
- 2- stone
- 3- brick
- 4- wood
- 5- cement
- 6- dirt
- 7- plank
- 8- snow
- 9- glass
- 10- cobble
- 11- light stone
- 12- dark stone
- 13- chest
- 14- leaves
- 15- tall grass
- 16- yellow flower
- 17- red flower
- 18- purple flower
- 19- sunflower
- 20- white flower
- 21- blue flower
- 22- oak sapling
- 23- birch sapling
- 24- yellow block
- 25- light green block
- 26- green block
- 27- teal block
- 28- dark green block
- 29- brown-green block
- 30- dark gray block
- 31- indigo block
- 32- light gray block
- 33- gray block
- 34- purple block
- 35- red block
- 36- light red block
- 37- pink block
- 38- very light green block
- 39- brown-yellow block
- 40- black block
- 41- very dark blue block
- 42- dark purple block
- 43- dusty red block
- 44- brown block
- 45- orange block
- 46- tan block
- 47- cream block
- 48- dark blue block
- 49- blue block
- 50- light blue block
- 51- turquoise block
- 52- powder blue block
- 53- white block
- 54- blue-gray block
- 55- purple-gray block
- 56- diamond
- 57- ruby
- 58- gold
- 59- birch wood
- 60- black stone

### Adding Block Textures

Adding block textures is a very simple process. It involves only a few steps:

- Download textures/[texture.png](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/textures/texture.png) and add your block texture(s) to the grid
- Replace the original [texture.png](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/textures/texture.png) file with your modified copy
- Open src/[item.h](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/src/item.h) and define your block at the bottom of the list of definitions ex. `#define NEWBLOCK 64`
- Open src/[item.c](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/src/item.c) and add your newly defined block to the array of blocks:
  ```
  const int items [] = {
      OLDBLOCK,
      NEWBLOCK
  };
  ```
- In src/[item.c](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/src/item.c) add your new block to `const int blocks[256][6] = { }` list.

This list defines which texture each block is given. It accepts 6 values (left, right, top, bottom, front, back). Each value is the location of a 16x16 pixel block on the [texture.png](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/textures/texture.png) image, starting from the bottom left corner at 0.

**Example:**
I want to define sand within the list. You can see that sand is on the bottom row of [texture.png](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/textures/texture.png), and one space in from the left. This means that sands texture map is (1, 1, 1, 1, 1, 1).

### Adding Plant Textures

Adding plant textures involves basically the same steps listed above: 

- Download textures/[texture.png](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/textures/texture.png) and add your plant texture(s) to the grid
- Replace the original [texture.png](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/textures/texture.png) file with your modified copy
- Open src/[item.h](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/src/item.h) and define your plant at the bottom of the list of definitions ex. `#define NEWPLANT 64`
- Open src/[item.c](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/src/item.c) and add your newly defined plant to the array of plants:
  ```
  const int items [] = {
      OLDPLANT,
      NEWPLANT
  };
  ```
- In src/[item.c](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/src/item.c) add your new block to `const int plants[256] = { }` list.

This list defines which texture each plant is given. It accepts 1 value which represents the texture's location in the grid. 

**Example**
If I want to define tall-grass within the list, the texture is located in the first position of the fourth row. 
The bottom left (grass block bottom) of textures.png is position 0, as you move right along the row the position increases by 1. When you reach the end of the row, you start on the left-most position of the row above and increase the account accordingly. 
Following this pattern, the grass block is located in position #48

### Screenshot

![Screenshot](http://i.imgur.com/foYz3aN.png)

### Implementation Details

#### Terrain Generation

The terrain is generated using Simplex noise - a deterministic noise function seeded based on position. So the world will always be generated the same way in a given location.

The world is split up into 32x32 block chunks in the XZ plane (Y is up). This allows the world to be ???infinite??? (floating point precision is currently a problem at large X or Z values) and also makes it easier to manage the data. Only visible chunks need to be queried from the database.

#### Rendering

Only exposed faces are rendered. This is an important optimization as the vast majority of blocks are either completely hidden or are only exposing one or two faces. Each chunk records a one-block width overlap for each neighboring chunk so it knows which blocks along its perimeter are exposed.

Only visible chunks are rendered. A naive frustum-culling approach is used to test if a chunk is in the camera???s view. If it is not, it is not rendered. This results in a pretty decent performance improvement as well.

Chunk buffers are completely regenerated when a block is changed in that chunk, instead of trying to update the VBO.

Text is rendered using a bitmap atlas. Each character is rendered onto two triangles forming a 2D rectangle.

???Modern??? OpenGL is used - no deprecated, fixed-function pipeline functions are used. Vertex buffer objects are used for position, normal and texture coordinates. Vertex and fragment shaders are used for rendering. Matrix manipulation functions are in matrix.c for translation, rotation, perspective, orthographic, etc. matrices. The 3D models are made up of very simple primitives - mostly cubes and rectangles. These models are generated in code in cube.c.

Transparency in glass blocks and plants (plants don???t take up the full rectangular shape of their triangle primitives) is implemented by discarding magenta-colored pixels in the fragment shader.

#### Database

User changes to the world are stored in a sqlite database. Only the delta is stored, so the default world is generated and then the user changes are applied on top when loading.

The main database table is named ???block??? and has columns p, q, x, y, z, w. (p, q) identifies the chunk, (x, y, z) identifies the block position and (w) identifies the block type. 0 represents an empty block (air).

In game, the chunks store their blocks in a hash map. An (x, y, z) key maps to a (w) value.

The y-position of blocks are limited to 0 <= y < 256. The upper limit is mainly an artificial limitation to prevent users from building unnecessarily tall structures. Users are not allowed to destroy blocks at y = 0 to avoid falling underneath the world.

#### Multiplayer

Multiplayer mode is implemented using plain-old sockets. A simple, ASCII, line-based protocol is used. Each line is made up of a command code and zero or more comma-separated arguments. The client requests chunks from the server with a simple command: C,p,q,key. ???C??? means ???Chunk??? and (p, q) identifies the chunk. The key is used for caching - the server will only send block updates that have been performed since the client last asked for that chunk. Block updates (in realtime or as part of a chunk request) are sent to the client in the format: B,p,q,x,y,z,w. After sending all of the blocks for a requested chunk, the server will send an updated cache key in the format: K,p,q,key. The client will store this key and use it the next time it needs to ask for that chunk. Player positions are sent in the format: P,pid,x,y,z,rx,ry. The pid is the player ID and the rx and ry values indicate the player???s rotation in two different axes. The client interpolates player positions from the past two position updates for smoother animation. The client sends its position to the server at most every 0.1 seconds (less if not moving).

Client-side caching to the sqlite database can be performance intensive when connecting to a server for the first time. For this reason, sqlite writes are performed on a background thread. All writes occur in a transaction for performance. The transaction is committed every 5 seconds as opposed to some logical amount of work completed. A ring / circular buffer is used as a queue for what data is to be written to the database.

In multiplayer mode, players can observe one another in the main view or in a picture-in-picture view. Implementation of the PnP was surprisingly simple - just change the viewport and render the scene again from the other player???s point of view.

#### Collision Testing

Hit testing (what block the user is pointing at) is implemented by scanning a ray from the player???s position outward, following their sight vector. This is not a precise method, so the step rate can be made smaller to be more accurate.

Collision testing simply adjusts the player???s position to remain a certain distance away from any adjacent blocks that are obstacles. (Clouds and plants are not marked as obstacles, so you pass right through them.)

#### Sky Dome

A textured sky dome is used for the sky. The X-coordinate of the texture represents time of day. The Y-values map from the bottom of the sky sphere to the top of the sky sphere. The player is always in the center of the sphere. The fragment shaders for the blocks also sample the sky texture to determine the appropriate fog color to blend with based on the block???s position relative to the backing sky.

#### Ambient Occlusion

Ambient occlusion is implemented as described on this page:

http://0fps.wordpress.com/2013/07/03/ambient-occlusion-for-minecraft-like-worlds/

#### Dependencies

- GLEW is used for managing OpenGL extensions across platforms.
- GLFW is used for cross-platform window management.
- CURL is used for HTTPS / SSL POST for the authentication process.
- lodepng is used for loading PNG textures.
- sqlite3 is used for saving the blocks added / removed by the user.
- tinycthread is used for cross-platform threading.

#### Documentation

Documentation has been completed through the use of [Doxygen](https://www.doxygen.nl/manual/install.html). The configuration file is located at [ADAD-Craft/dconfig](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/dconfig).

To update the configuration file:

- Make changes to config file at [ADAD-Craft/dconfig](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/dconfig)
- Open your terminal on a machine with doxygen installed and change directories to your project repository
- Use the command: `doxygen dconfig`

That command will recompile the doxygen website based on the new settings in your dconfig file. You can also use `doxygen -g config_file_name` to create a fresh config file to work out of for your project.

### Testing

Testing has been completed with the [Unity](https://github.com/ThrowTheSwitch/Unity) testing library for C. The Unity library features a variety of tests for C programming, most of which are described on their GitHub repository linked above. A few of the tests that you can find within our program are:

- `TEST_ASSERT_TRUE(condition)` (fails if the code within the condition evaluates to false)
- `TEST_ASSERT_FALSE(condition)` (fails if the code within the condition evaluates to true)
- `TEST_ASSERT(condition)` (a simpler way of calling TEST_ASSET_TRUE)

Files related to unity testing can be found within [ADAD-Craft/src](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/tree/master/src). These files include:

- [unity.c](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/src/unity.c)
- [unity.h](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/src/unity.h)
- [unity_internals.h](https://github.com/WSU-CEG-6110-4410/ADAD-Craft/blob/master/src/unity_internals.h)

If you have any other concerns about Unity's testing framework, then here is a link to their [getting started guide](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityGettingStartedGuide.md).
