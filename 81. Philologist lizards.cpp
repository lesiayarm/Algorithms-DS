#include <iostream>
#include <vector>
#include <cstdint>

int n;
std::vector<std::vector<std::vector<int64_t>>> dp(42, std::vector<std::vector<int64_t>>(3, std::vector<int64_t>(3, -1)));

int64_t do_dp(int i, int a, int b) {
    if (i == n) {
        return 1;
    }
    if (a != -1 && b != -1 && dp[i][a][b] != -1) {
        return dp[i][a][b];
    }
    
    int64_t result = 0;
    for (int c = 0; c <3; ++c) {
        if (a == 0 && b == 1 && c == 2) continue;
        if (a == 1 && b == 1 && c == 1) continue;
        if (a == 2 && b == 2 && c == 2) continue;
        result += do_dp(i + 1, b, c);
    }
    if (a != -1  && b != -1) {
        dp[i][a][b] = result;
    }
    return result;
}

int main() {
    int64_t k;
    std::cin >> n >> k;
    std::vector<int> result(n, 0);
    int a = -1;
    int b = -1;
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < 3; ++ c) {
            if (a == 0 && b == 1 && c == 2) continue;
            if (a == 1 && b == 1 && c == 1) continue;
            if (a == 2 && b == 2 && c == 2) continue;
            int64_t temp = do_dp(i + 1, b, c);
            if (k > temp) {
                k -= temp;
                continue;
            }
            result[i] = c;
            a = b;
            b = c;
            break;
        }
    }
    for (auto& x : result) {
        if (x == 0) {
            std::cout << "chu";
        } else if (x == 1) {
            std::cout << "ka";
        } else {
            std::cout << "pi";
        }
    }
    std::cout << '\n';
    return 0;
}
