#include "Maze.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    cout << "Vvedite razmer labirinta: ";
    cin >> size;

    Maze maze(size);
    maze.generate();

    cout << "Generacia labirinta:\n";
    maze.display();

    // ���������� ��������� � �������� �����
    int startX = 0, startY = 1;
    int endX = size - 1, endY = size - 2;

    // ����� ����������� ����
    vector<pair<int, int>> path;
    if (maze.findShortestPathDFS(startX, startY, endX, endY, path)) {
        cout << "Put:\n";
//        for (const auto& p : path) {
//            cout << "(" << p.first << ", " << p.second << ") ";
//        }

        // ���������� ����� ����
        int pathLength = maze.calculatePathLength(path);
        cout << "Dlina puti: " << pathLength << " shagov." << endl;
    }
    else {
        cout << "Put ne naiden.\n";
    }
    cout << endl;
    // ����� ����������� ���� ������� ��������
    if (maze.findShortestPathDijkstra(startX, startY, endX, endY, path)) {
        cout << "Put (Dijkstra):\n";
//       for (const auto& p : path) {
//             cout << "(" << p.first << ", " << p.second << ") ";
//        }

        // ���������� ����� ����
        int pathLength = maze.calculatePathDijkstraLength(path); 
        cout << "Dlina puti: " << pathLength << " shagov." << endl;
    }
    else {
        cout << "Put ne naiden (Dijkstra).\n";
    }
    cout << endl;
   


    return 0;
}


