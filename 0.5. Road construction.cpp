#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <unordered_map>

class DSU {
public:
    void MakeSet(int x) {
        data[x] = x;
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
    std::array<int, 500000> data;
    std::unordered_map<int, int> rank;
};
 
int main()
{
    std::ifstream cin("input.txt");
    int n;
    int q;
    cin >> n >> q;
    std::ofstream cout("output.txt");
    DSU object;
    for (int i = 0; i < n; ++i) {
        object.MakeSet(i);
    }
    int counter = n;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (object.Find(u) != object.Find(v)) {
            --counter;
            object.Unite(u, v);
        }
        cout << counter << '\n';
        
    }
    return 0;
}
