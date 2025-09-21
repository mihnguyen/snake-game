/*
Snake game in C++
- An empty space: ' '
- A wall: '#'
- A snake body part: 'o'
- The food: '@'
*/


#include <iostream>
using namespace std;

/*
Step 1: Create game grid

Storing the 2D grid data (e.g., a char array).
Initializing the grid (setting up the walls and empty spaces).
Printing the grid to the console.
Providing methods to check if a position is a wall.
*/ 

// Approach 1: 2D array for 20x20 fixed-size grid
class GameGrid {
    int grid_height = 20;
    int grid_width = 20;
    // Declare 20x20 game grid
    char game_grid[grid_height][grid_width];

    // Initialize grid with # for walls, and empty spaces to represent an empty game board.
    // Store data (or game state) in gameGrid[i][j], instead of using std::cout,
    // which wouldn't allow for tracking positions.
    for (int i = 0; i < grid_height; ++i) {
        if (i = 0) {
            game_grid[i][j] = '#';
        }
        else {
            for (int j = 0; j < grid_width; ++j) {
                if (j = 0) {
                    game_grid[i][j] = '#';
                }
                else {
                    game_grid[i][j] = ' ';
                }
            }
        }
    }

    // Print grid with initial positions
    for (int i = 0; i < grid_height; ++i) {
        for (int j = 0; j < grid_width; ++j) {
            cout << game_grid[i][j];
        }
        cout << endl;
    }
};

// Approach 2: std::vector of std::vector
// ...


/*
Step 2: Create snake's body
Storing the snake's body coordinates (e.g., a std::vector of Point structs).
Handling the snake's movement (updating coordinates based on direction).
Managing the snake's growth when it eats food.
Checking for self-collision.
By defining a struct to store coordinates of body segments.
Loop through the snakeBody vector. 
For each Point object in the vector, update the corresponding 
cell in the gameGrid to the snake body character 'o'.
*/ 

class Snake {

    /*
    Initialize snake's head at a random position by generating random coordinates.
    Valid x-coordinates are from 0 to (grid_height-1). Similarly for y-coordinates.
    However, snake body must not be on 4 walls of the grid. 
    Thus, safe range for snake is x=1 to x=grid_height-2. Similarly for y-coordinates.
    The expression rand() % N generates a random number in the range [0, N-1].
    Our desired safe range for the y-coordinate is from 1 to grid_height - 2. 
        The number of available spots in this range is (grid_height - 2) - 1 + 1 = grid_height - 2.
    To get a random number in this range [1, grid_height - 2], 
        we first need to generate a random number in the range [0, (grid_height - 2) - 1], 
        which is [0, grid_height - 3].
    We achieve this by using the modulo operator with N = (grid_height - 2). 
        So, rand() % (grid_height - 2) gives us a random number from 0 up to grid_height - 3.
    */    
    // Function to generate a random number within range [min, max]
    int get_random_number(int min, int max) {
        // Total number of values in the range
        int range = max - min + 1;
        // Generate a random number from 0 to (range-1) and then shift it
        return rand() % range + 1;
    }

    srand(time(0));  // Seed the random number generator
    int min_safe_x = 1;
    int max_safe_x = grid_height - 2;
    int min_safe_y = 1;
    int max_safe_y = grid_width - 2;

    int start_x = get_random_number(min_safe_x; max_safe_x);
    int start_y = get_random_number(min_safe_y; max_safe_y);

    // Constructor to store snake's starting position
    Snake(int start_x, int start_y);

    // Define a struct to hold a coordinate point
    struct point {
        int x;
        int y;
    };

    // Create vector to store multiple `point` objects, representing entire snake body
    vector<point> snake_body;
};


/*
Acts as the game manager. It brings together the GameGrid and Snake objects 
and orchestrates the game's flow.
Initializing the GameGrid and Snake objects.
Handling the main game loop.
Getting user input.
Calling methods from the Snake and GameGrid classes to update and render the game state.
Checking for game-over conditions.
*/
int main() {

}

