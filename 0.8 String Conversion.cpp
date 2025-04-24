#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream cin("in.txt");
    int x, y, z;
    cin >> x >> y >> z;
    std::string first, second;
    cin >> first >> second;
    std::vector<std::vector<int> > matrix(second.size() + 1, std::vector<int>(first.size() + 1));
    for (int i = 0; i < first.size() + 1; ++i) {
        matrix[0][i] = i * x;
    }
    for (int j = 0; j < second.size() + 1; ++j) {
        matrix[j][0] = j * y;
    }
    for (int i = 1; i < second.size() + 1; ++i) {
        for (int j = 1; j < first.size() + 1; ++j) {
            int k = (first[j - 1] == second[i - 1]) ? 0 : z;
            matrix[i][j] = std::min(std::min(matrix[i - 1][j] + y, matrix[i][j - 1] + x), matrix[i - 1][j - 1] + k);
        }
    }
    std::ofstream cout("out.txt");
    cout << matrix[second.size()][first.size()];
    return 0;
}
