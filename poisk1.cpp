#include "Maze.h"


using namespace std;

// ������� ��� ������ ����������� ���� � �������������� DFS
bool Maze::naxogdeniecrotchaishegoputiDFS(int startX, int startY, int endX, int endY, vector<pair<int, int>>& path) {
    auto start = std::chrono::high_resolution_clock::now();  // ������ ������ �������

    vector<vector<bool>> visited(size, vector<bool>(size, false));
    vector<pair<int, int>> currentPath;
    bool found = dfs(startX, startY, endX, endY, currentPath, visited);

    auto end = std::chrono::high_resolution_clock::now();  // ����� ������ �������
    std::chrono::duration<double> duration = end - start;  // ��������� ������������
    std::cout << "Vremya poiska (DFS): " << duration.count() << " sekund." << std::endl;

    if (found) {
        path = currentPath;
        return true;
    }
    return false;
}




// ��������������� ������� DFS ��� ������ ����
bool Maze::dfs(int x, int y, int endX, int endY, vector<pair<int, int>>& path, vector<vector<bool>>& visited) {
    // ���� �������� �����, ��������� ����
    if (x == endX && y == endY) {
        path.push_back({ x, y });
        return true;
    }

    // ��������� ������� � ������������ ������
    if (!vlabirinte(x, y) || labyrinth[x][y] == Stena || visited[x][y]) {
        return false;
    }

    visited[x][y] = true;
    path.push_back({ x, y });

    // ��������������� ������� ��� ����������� ��������
    const int dx[] = { 0, 1, 0, -1 };  // ������, ����, �����, �����
    const int dy[] = { 1, 0, -1, 0 };

    // ����������� ����� � ������ �����������
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (dfs(newX, newY, endX, endY, path, visited)) {
            return true;
        }
    }
    
    path.pop_back(); // ������� �� ����, ���� �� ������� ������
    visited[x][y] = false; // �������� ��� ������������ ��� ������ �����
    return false;
}


// ������� ��� ���������� ����� ����
int Maze::calculatePutiLength(const vector<pair<int, int>>& path) {
    return path.size() - 1;  // ����� ���� � ����� (������ ���� ����� ����)
}
