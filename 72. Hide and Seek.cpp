#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

struct Node {
    int64_t w;
    int l;
    int r;
    int index;
};

struct Element {
    int64_t w;
    int index;
};

class Fenvik_tree {
public:
    Fenvik_tree(int n) {
        data_.resize(n + 1);
        size = n;
    }
    
    int64_t res(int l, int r) {
        int64_t result = 0;
        while (r > 0) {
            result += data_[r];
            r -= r & (-r);
        }
        --l;
        while (l > 0) {
            result -= data_[l];
            l -= l & (-l);
        }
        return result;
    }
    
    void update (int index) {
        while (index <= size) {
            data_[index] += 1;
            index += index & (-index);
        }
    }

private:
    std::vector<int64_t> data_;
    int size;
    
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    std::vector<Element> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].w;
        a[i].index = i + 1;
    }
    std::sort(a.begin(), a.end(),
              [](const auto& f, const auto& s){return f.w < s.w;});
    
    std::vector<Node> requests(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> requests[i].l >> requests[i].r >> requests[i].w;
        requests[i].index = i;
    }
    std::sort(requests.begin(), requests.end(),
              [](const auto& i, const auto& j){return i.w < j.w;});
    
    std::vector<int64_t> result(q);
    auto ftree = Fenvik_tree(n);
    int index = 0;
    for (const auto& x : requests) {
        while (index < n && a[index].w <= x.w) {
            ftree.update(a[index].index);
            ++index;
        }
        result[x.index] = ftree.res(x.l, x.r);
    }
    
    for (auto& x : result) {
        std::cout << x << '\n';
    }
    return 0;
}
