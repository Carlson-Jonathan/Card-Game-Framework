DESCRIPTION:
    The classic card game 'War' made with the SFML framework. Based on my Game-Framework repository.
    This game was made primarily to get a feel for making C++ card games in SFML so I could move on
    to making more advanced card games.


DEPENDENCIES:
    C++ 11,
    SFML (Get it here: https://www.sfml-dev.org/index.php)


COMPILE INSTRUCTIONS (CMake):
Note: Only step 4 will be used in most cases unless you need to remake the 'build' folder.

    1.) Create build folder (if doesnt exist). 
    2.) cd into build folder.
    3.) Run command: "cmake .." (auto config) or "ccmake .." (manual config) 
    	If manual, configure anything needed but you should only need to add "Debug" to the 1 blank. 
        Hit "c" to create crap. If it works, a "g" option will appear to generate and exit.
    4.) Run command: "make" This will create a "Main.out" executable in the source folder.


COMPILE INSTRUCTIONS (g++):
    If CMake isnt working, you can use the 'compileAndRun.bash' script. Run as is. 
    
![](FrameworkUML.png)
