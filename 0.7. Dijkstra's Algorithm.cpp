#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>
#include <list>
#include <queue>
#include <unordered_map>


struct V {
    int64_t weight;
    int v;
};

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int n, m;
    cin >> n >> m;
    std::unordered_map<int, std::unordered_map<int, int64_t>> information;
    int u, v;
    int64_t w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        --u;
        --v;
        if (!information.contains(u) || !information[u].contains(v)) {
            information[u][v] = w;
            information[v][u] = w;
            continue;
        }
        information[u][v] = std::min(information[u][v], w);
        information[v][u] = information[u][v];
    }
    
    std::vector<std::pair<int64_t, bool>> dist(n, {std::numeric_limits<int64_t>::max(), true});
    dist[0] = {0, true};
    using T = std::pair<int64_t, int>;
    std::priority_queue<T, std::vector<T>, std::greater<T>> queue;
    queue.push({0, 0});
    while (!queue.empty()) {
        auto min_el = queue.top();
        queue.pop();
        v = min_el.second;
        w = min_el.first;
        if (dist[v].second) {
            dist[v].second = false;
        }
        for (auto x : information[v]) {
            int64_t temp_weight = w + x.second;
            if (dist[x.first].first > temp_weight) {
                queue.push({temp_weight, x.first});
            }
            dist[x.first].first = std::min(dist[x.first].first, temp_weight);
        }
    }
    cout << dist[n - 1].first;
    return 0;
}
