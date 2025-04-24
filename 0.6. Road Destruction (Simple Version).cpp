#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

struct MyPair {
    int u;
    int v;
    bool flag = true; // не разрушаем
};

class DSU {
public:
    void MakeSet(int x) {
        data[x] = x;
        rank[x] = 0;
    }
    
    int Find(int x) {
        if (data[x] == x) {
            return x;
        }
        return data[x] = Find(data[x]);
    }
    
    void Unite(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (rank[x] == rank[y]) {
            ++rank[y];
            data[x] = y;
            return;
        }
        if (rank[x] < rank[y]) {
            data[x] = y;
        } else {
            data[y] = x;
        }
    }
    
private:
    std::array<int, 100000> data;
    std::unordered_map<int, int> rank;
};
 
int main()
{
    std::ifstream cin("input.txt");
    int n, m, q;
    cin >> n >> m >> q;
    std::ofstream cout("output.txt");
    DSU object;
    for (int i = 0; i < n; ++i) {
        object.MakeSet(i);
    }
    
    std::vector<MyPair> roads(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        roads[i] = {u - 1, v - 1, true};
    }
    
    
    std::vector<int> index(q);
    int counter = n;
    for (int i = q - 1; i >= 0; --i) {
        int index_of_road;
        cin >> index_of_road;
        index[i] = index_of_road - 1;
        roads[index_of_road - 1].flag = false;
    }
    int count_of_null = 0;
    for (int i = 0; i < m; ++i) {
        if (counter == 1) {
            for (int j = 0; j < q; ++j) {
                cout << 1;
            }
            return 0;
        }
        auto temp = roads[i];
        if (temp.flag) {
            if (object.Find(temp.u) == object.Find(temp.v)) {
                continue;
            }
            --counter;
            object.Unite(temp.u, temp.v);
        }
    }
    for (int i = 0; i < q; ++i) {
        if (counter <= 1) {
            break;
        }
        ++count_of_null;
        auto temp = roads[index[i]];
        if (object.Find(temp.u) == object.Find(temp.v)) {
            continue;
        }
        --counter;
        object.Unite(temp.u, temp.v);
    }
    int for_edin = q - count_of_null;
    while (for_edin > 0) {
        --for_edin;
        cout << 1;
    }
    while (count_of_null > 0) {
        --count_of_null;
        cout << 0;
    }
    return 0;
}
