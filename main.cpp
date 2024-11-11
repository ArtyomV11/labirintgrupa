#include "Maze.h"

using namespace std;

int main() {
    int size;
    cout << "Vvedite razmer labirinta: ";
    cin >> size;

    Maze maze(size);
    maze.generation();
 

    cout << "Generacia labirinta:\n";
    maze.pokaz();

 
    int startX = 0, startY = 1;
    int endX = size - 1, endY = size - 2;


    vector<pair<int, int>> path;
    if (maze.naxogdeniecrotchaishegoputiDFS(startX, startY, endX, endY, path)) {
        cout << "--Poisk puti metodom dfs--\n";
//        for (const auto& p : path) {
//            cout << "(" << p.first << ", " << p.second << ") ";
//        }

    
        int pathLength = maze.calculatePutiLength(path);
        cout << "Dlina puti: " << pathLength << " shagov." << endl;
    }
    else {
        cout << "Put ne naiden.\n";
    }
    cout << endl;

    if (maze.naxogdeniecrotchaishegoputiDijkstra(startX, startY, endX, endY, path)) {
        cout << "--Poisk puti metodo Djjkstra--\n";
//      for (const auto& p : path) {
//             cout << "(" << p.first << ", " << p.second << ") ";
//        }

       
        int pathLength = maze.calculatePutiDijkstraLength(path); 
        cout << "Dlina puti: " << pathLength << " shagov." << endl;
    }
    else {
        cout << "Put ne naiden (Dijkstra).\n";
    }
    cout << endl;
   


    return 0;
}


