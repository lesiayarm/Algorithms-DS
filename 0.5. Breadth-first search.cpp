#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

int counter = 1;

void bfs(std::vector<std::vector<int>>& matrix, std::vector<int>& tags, int u, int n, std::queue<int>& work) {
    if (tags[u] != -1) {
        return;
    }
    tags[u] = counter;
    ++counter;
    int j = 0;
    while (j < n) {
        if (matrix[u][j] != 1) {
            ++j;
            continue;
        }
        if (matrix[u][j] == 1) {
            matrix[u][j] = 0;
            work.push(j);
        }
        ++j;
    }
}

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int n;
    cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    std::vector<int> tags(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    std::queue<int> work;
    for (int i = 0; i < n; ++i) {
        if (tags[i] == -1) {
            work.push(i);
            while (!work.empty()) {
                bfs(matrix, tags, work.front(), n, work);
                work.pop();
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << tags[i] << " ";
    }
    return 0;
}
