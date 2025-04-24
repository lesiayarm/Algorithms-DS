#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

int64_t func(std::vector<std::vector<int> >& matrix, int i, int j, std::vector<std::pair<int, int> >& data) {
    if (i == j) {
        return 0;
    }
    if (i == j - 1) {
        return data[i].first * data[i].second * data[j].second;
    }
    int k = i;
    int64_t temp_res = matrix[k + 1][j] + data[i].first * data[k].second * data[j].second;
    while (k != j) {
        int64_t temp = matrix[i][k] +  matrix[k + 1][j] + data[i].first * data[k].second * data[j].second;
        temp_res = std::min(temp, temp_res);
        ++k;
    }
    return temp_res;
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int n;
    in >> n;
    std::vector<std::pair<int, int> > data(n);
    for (auto& x : data) {
        in >> x.first >> x.second;
    }
    std::vector<std::vector<int> > matrix(n, std::vector<int>(n, 0));
    for (int j = 0; j < n; ++j) {
        for (int i = j; i >= 0; --i) {
            matrix[i][j] = func(matrix, i, j, data);
        }
    }
    out << matrix[0][n - 1];
    return 0;
}
