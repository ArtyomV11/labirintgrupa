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
#include <climits>
#include <queue>
#include <tuple>

const char Stena = '#';
const char Put = ' ';

class Maze {


public:
    Maze(int size);
    void generation();
    void pokaz() const;
    void sochranenievfail(const std::string& filename) const;
    bool naxogdeniecrotchaishegoputiDFS(int startX, int startY, int endX, int endY, std::vector<std::pair<int, int>>& path);
    int calculatePutiLength(const std::vector<std::pair<int, int>>& path);
    bool naxogdeniecrotchaishegoputiDijkstra(int startX, int startY, int endX, int endY, std::vector<std::pair<int, int>>& path);
    int calculatePutiDijkstraLength(const std::vector<std::pair<int, int>>& path);

private:
    int size;
    std::vector<std::vector<char>> labyrinth;
    bool vlabirinte(int x, int y) const;
    void sozdanieputi(int x, int y);
    bool dfs(int x, int y, int endX, int endY, std::vector<std::pair<int, int>>& path, std::vector<std::vector<bool>>& visited);
};


#endif

