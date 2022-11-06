# CPPND: Capstone Snake Game with additions by Joel Kelly

This project started from a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## How the Game Operates & Class Structure
### Game Flow
The snake game operates under the typical input/update/render loop: the `Controller` class is responsible for handling user input in this case. 

Once the user input is handled, various properties of the game's artifacts (notably, the snake and the food) are updated based on certain properties. Some of what happens under the hood is:
- Check to see if the snake's head overlaps with itself
- Update the snake's body (represented by a vector) and check for collision status
- Check to see if the snake's head overlaps with the food, and update the food's location, score of the game, and snake's length properly

Finally, after the new state of the world is in order (snake's direction/body, updated food if applicable) - the `Renderer` class handles rendering the new `Game` layout.

### Class structure
As described above, `Controller` and `Renderer` handle user input/rendering the game visually. Under the hood, there is **class composition** in the sense that a `Game` object *has a* `Snake` object and a `Food` object. 

A new base class is defined called `GameObject`: both `Snake` and `Food` are `GameObject`s (**class inheritance**).

## Rubric requirements
The code compiles and runs, and the README here has been updated to provide users the ability to build and run the game, and understand its contents + class structure. 

Outside of these core requirements, the other 5 requirements met are:
1. The project uses Object Oriented Programming techniques: *The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.*
  - Described class structure in detail above.
2. Classes use appropriate access specifiers for class members: *All class data members are explicitly specified as public, protected, or private.*
  - See files under `src` subdir for details.
3. Class constructors utilize member initialization lists: *All class members that are set to argument values are initialized through member initialization lists.*
  - See examples, in particular, for classes `GameObject`, `Snake`, and `Food`
4. Classes abstract implementation details from their interfaces: *All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.*
5. Classes encapsulate behavior: *Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.*
  - Took special care to ensure classes have proper get/set methods to not allow users to directly interface with private member variables
6. Classes follow an appropriate inheritance hierarchy: *Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified.*
  - See class implementation details above for inheritance vs. composition for structure of the game.

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
