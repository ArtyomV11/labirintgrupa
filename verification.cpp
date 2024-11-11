#include "Maze.h"

void verifyMazeGeneration(int size) {
    Maze maze(size);
    maze.generation();
    std::cout << "Generated maze of size " << size << ":\n";
    maze.pokaz();
}

void verifyMazeSaving(int size, const std::string& filename) {
    Maze maze(size);
    maze.generation();
    maze.sochranenievfail(filename);
    std::cout << "Maze saved to " << filename << std::endl;
}