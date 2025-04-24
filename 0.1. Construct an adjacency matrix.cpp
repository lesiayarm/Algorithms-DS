#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int n, m;
    cin >> n >> m;
    std::vector<std::vector<bool>> matrix(n, std::vector<bool>(n));
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        matrix[u][v] = true;
        matrix[v][u] = true;
    }
    for (const auto& x : matrix) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << '\n';
    }
    return 0;
}
