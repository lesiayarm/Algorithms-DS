#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int n;
    cin >> n;
    int flag;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> flag;
            if (flag == 0) {
                continue;
            }
            p[j] = i + 1;
        }
    }
    for (auto& x : p) {
        cout << x << " ";
    }
    return 0;
}
