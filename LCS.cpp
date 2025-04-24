#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> first_subsequence(n);
    std::vector<int> second_subsequence(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> first_subsequence[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> second_subsequence[i];
    }

    std::vector<std::vector<int> > matrix(n + 1, std::vector<int> (n + 1));
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <=n; ++i) {
            if (first_subsequence[i - 1] == second_subsequence[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    std::cout << '\n';
    int i = n;
    int j = n;
    int temp = matrix[i][j];
    std::vector<int> res_1(temp);
    std::vector<int> res_2(temp);
    while (temp > 0) {
        if (first_subsequence[i - 1] == second_subsequence[j - 1]) {
            res_1[temp - 1] = i - 1;
            res_2[temp - 1] = j - 1;
            --i;
            --j;
            --temp;
            continue;
        }
        while (matrix[i][j] == matrix[i][j - 1]) {
            --j;
        }
        while (matrix[i - 1][j] == matrix[i][j]) {
            --i;
        }
    }
    std::cout << res_1.size() << '\n';
    for (const auto& x : res_1) {
        std::cout << x << " ";
    }
    std::cout << '\n';
    for (const auto& x : res_2) {
        std::cout << x << " ";
    }
    return 0;
}
