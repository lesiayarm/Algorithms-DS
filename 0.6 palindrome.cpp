#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    std::string first_subsequence, second_subsequence;
    cin >> first_subsequence;
    size_t n = first_subsequence.size();
    second_subsequence = first_subsequence;
    std::reverse(second_subsequence.begin(), second_subsequence.end());
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
    size_t i = n, j = n;
    int length = matrix[n][n];  
    std::string lcs(length, ' ');
    while (length > 0) {
        if (first_subsequence[i - 1] == second_subsequence[j - 1]) {
            lcs[length - 1] = first_subsequence[i - 1]; 
            --i;
            --j;
            --length;
            continue;
        }
        if (matrix[i - 1][j] == matrix[i][j]) {
            --i;
        }
        else if (matrix[i][j] == matrix[i][j - 1]) {
            --j;
        }
    }


    cout << lcs.size() << '\n';
    cout << lcs << '\n';
    return 0;
}
