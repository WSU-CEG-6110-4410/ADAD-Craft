# TerrainBuilder
This is for Group15 Terrain Builder Project 

An extension of Craft to procedurally generate terrain from Erik Buck’s GitHub. [GitHublink](https://github.com/erikbuck/Craft)

We use a free open-source Doxygen Doxygen program generation tool, which can convert specific comments in the program into a description file. The use of Doxygen can be divided into two parts. The first part is to write comments in a specific format, and the second is to use it to generate documents.

For this project, we are using Doxygen to produce a Software Design Document (SDD), we are using Doxygen to document traceability from design to requirements (all tracebility doxygen documentation comment are show in modified and added soure code file and test file), we are using Doxygen to generate formatted code documentation.

For generating Doxygen documentation for code implementations and main.c code changes:
cd into the src directory and execute the command "doxygen". Open the index.html file. Under the modules tab there will be documentation for all added .h/.c files and functions, inside of the files tab, the code added to the various source files documentation (including changes to main.c) can be viewed with links to the requirements they correspond to.

To test requirements 10, 11, 12, and 19 implementations:
Requires GCC
cd into the src directory
cd into Jonathan_Test_Requirements
execute commands:
g++ -g Jonathan_Requirements10_11_12_19.h Jonathan_Requirements10_11_12_19.c Jonathan_Testbench.c; 
./a.out

The print statements track program execution through the random number generation of a movement speed value, precipitation type (enum value 0-2 currently with support for more to be added), and state what the randomly generated values are and what is recieved by the structs after the set functions. Running the game following the README.md provided by the original author allows the changes to be seen in game currently no precipitation is visual, but the reduced render radius updates based on movement speed and the generated weather condition are visible.

Doxygen documentation is availible for the entire Jonathan_Test_Requirements directory. Simply cd to the directory and execute "doxygen" in terminal. Inspecting the index.html in the "Modules" tab there will be a Jonathan_Terrain_Mods module item containing some redundant documentation of the Jonathan_Requirements10_11_12_19.h and .c files as well as new documentation of the test bench highlighting which methods test which requirements with links to each requirement.

Inspecting the index.html in the "Modules" tab there will be a Jonathan_Terrain_Mods module item containing some redundant documentation of the Jonathan_Requirements10_11_12_19.h and .c files as well as new documentation of the test bench highlighting which methods test which requirements.

Doxygen documentation exists for changes within main.c, item.c, and world.c, as modified by Alex Gentry.

Doxygen documentation exists for req14,14.1,15,15.1,15.2 in Req14Speed.cpp, Req14Speed.hpp, Req15Flower.cpp, Req15Flower.hpp. And also Test file for req14,14.1,15,15.1,15.2 in Req14_15Test.cpp, as modified by Haiyue Chen.

