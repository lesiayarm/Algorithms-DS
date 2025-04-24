#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <limits>

int n;

bool bfs(const std::vector<std::vector<int64_t>>& capacity, std::vector<int>& parent) {
    std::fill(parent.begin(), parent.end(), -1);
    parent[1] = -2;
    std::queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; ++v) {
            if (capacity[u][v] > 0 && parent[v] == -1) {
                parent[v] = u;
                if (v == n) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int64_t maxFlow(std::vector<std::vector<int64_t>>& capacity) {
    int64_t result = 0;
    std::vector<int> parent(n + 1);
    while (bfs(capacity, parent)) {
        int64_t min_capacity = std::numeric_limits<int64_t>::max();
        for (int v = n; v != 1; v = parent[v]) {
            min_capacity = std::min(min_capacity, capacity[parent[v]][v]);
        }
        for (int v = n; v != 1; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= min_capacity;
            capacity[v][u] += min_capacity;
        }
        result += min_capacity;
    }
    return result;
}

int main() {
    int m;
    std::cin >> n >> m;
    std::vector<std::vector<int64_t>> data(n + 1, std::vector<int64_t>(n + 1, 0));
    int u, v;
    int64_t w;
    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v >> w;
        data[u][v] += w;
    }
    std::cout << maxFlow(data) << '\n';
    return 0;
}
