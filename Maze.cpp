#include "Maze.h"

using namespace std;

const int dx[] = { 2, 0, -2, 0 };
const int dy[] = { 0, 2, 0, -2 };

Maze::Maze(int size) : size(size), labyrinth(size, vector<char>(size, Stena)) {
    srand(static_cast<unsigned>(time(0))); 
}

bool Maze::vlabirinte(int x, int y) const {
    return x >= 0 && x < size  && y >= 0 && y < size ;
}


void Maze::sozdanieputi(int x, int y) {
    labyrinth[x][y] = Put;
    vector<int> directions = { 0, 1, 2, 3 };

    
    for (int i = directions.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(directions[i], directions[j]);
    }

    for (int dir : directions) {
        int newX = x + dx[dir];
        int newY = y + dy[dir];
        if (vlabirinte(newX, newY) && labyrinth[newX][newY] == Stena) {
            labyrinth[x + dx[dir] / 2][y + dy[dir] / 2] = Put;
            sozdanieputi(newX, newY);
        }
    }
}

void Maze::generation() {
    auto start = std::chrono::high_resolution_clock::now();  

    labyrinth.assign(size, vector<char>(size, Stena));
    sozdanieputi(1, 1);
    labyrinth[0][1] = Put; 
    labyrinth[size - 1][size - 2] = Put; 

    auto end = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> duration = end - start;  
    std::cout << "Vremya generacii labirinta: " << duration.count() << " sekund." << std::endl;
}


void Maze::pokaz() const {
    for (const auto& row : labyrinth) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

void Maze::sochranenievfail(const string& filename) const {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& row : labyrinth) {
            for (char cell : row) {
                outFile << cell;
            }
            outFile << endl;
        }
        outFile.close();
        cout << "Labirint sohraneny v fail: " << filename << endl;
    }
    else {
        cerr << "Ne udalos' otkryt' fail dlya zapisi." << endl;
    }
}

