#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    std::vector<int> data(n);
    std::vector<int> temp_results;
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    temp_results.push_back(data[0]);
    for (int i = 1; i < n; ++i) {
        auto x = std::lower_bound(temp_results.begin(), temp_results.end(), data[i]);
        if (x == temp_results.end()) {
            if (*(x - 1) != data[i]) {
                temp_results.push_back(data[i]);
            }
            continue;
        }
        if (x == temp_results.begin() && *(x - 1) == data[i]) {
            continue;
        }
        *x = data[i];
    }
    cout << temp_results.size() << '\n';
    return 0;
}
