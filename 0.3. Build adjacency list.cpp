#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int n, m;
    cin >> n >> m;
    std::vector<std::stack<int>> data(n);
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        data[u - 1].push(v);
        data[v - 1].push(u);
    }
    for (auto& x : data) {
        size_t size = x.size();
        cout << size << " ";
        while (size != 0) {
            cout << x.top() << " ";
            x.pop();
            --size;
        }
        cout << '\n';
    }
    return 0;
}
