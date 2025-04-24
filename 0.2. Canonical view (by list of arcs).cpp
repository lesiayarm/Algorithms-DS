#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int n;
    cin >> n;
    std::vector<int> p(n, 0);
    int dad, child;
    for (int i = 0; i < n - 1; ++i) {
        cin >> dad >> child;
        p[child - 1] = dad;
    }
    for (auto& x : p) {
        cout << x << " ";
    }
    return 0;
}
