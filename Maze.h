#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <utility>
#include <chrono>

const char Stena = '#';
const char Put = ' ';

class Maze {
public:
    Maze(int size);
    void generate();
    void display() const;
    void saveToFile(const std::string& filename) const;
    bool findShortestPathDFS(int startX, int startY, int endX, int endY, std::vector<std::pair<int, int>>& path);
    int calculatePathLength(const std::vector<std::pair<int, int>>& path);
    bool findShortestPathDijkstra(int startX, int startY, int endX, int endY, std::vector<std::pair<int, int>>& path);
    int calculatePathDijkstraLength(const std::vector<std::pair<int, int>>& path);




private:
    int size;
    std::vector<std::vector<char>> labyrinth;
    bool inBounds(int x, int y) const;
    void createPath(int x, int y);
    bool dfs(int x, int y, int endX, int endY, std::vector<std::pair<int, int>>& path, std::vector<std::vector<bool>>& visited);
    

};

#endif