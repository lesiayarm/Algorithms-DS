#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

int64_t FindSum(const std::vector<std::pair<int64_t, int64_t>>& data, int l, int r, int block_lenght) {
    int number_of_block_l = l / block_lenght;
    int number_of_block_r = r / block_lenght;
    if (number_of_block_l == number_of_block_r) {
        return data[r].second - data[l].second;
    }
    auto last_l = data[(1 + number_of_block_l) * block_lenght - 1];
    int64_t result = last_l.first + last_l.second - data[l].second;
    result += data[r].second;
    for (int i = number_of_block_l + 1; i < number_of_block_r; ++i) {
        auto last_elem = data[(1 + i) * block_lenght - 1];
        result += last_elem.second + last_elem.first;
    }
    return result;
}

void Add(std::vector<std::pair<int64_t, int64_t>>& data, int64_t i, int64_t x, int block_lenght) {
    data[i].first += x;
    ++i;
    if (i % block_lenght == 0) {
        return;
    }
    while (i % block_lenght != 0 && i != data.size()) {
        data[i].second = data[i - 1].second + data[i - 1].first;
        ++i;
    }
}
 
int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int64_t n;
    std::cin >> n;
    int block_lenght = std::sqrt(n);
    std::vector<std::pair<int64_t, int64_t>> data(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i].first;
        if (i % block_lenght == 0) {
            data[i].second = 0;
        } else {
            data[i].second = data[i - 1].second + data[i - 1].first;
        }
    }
    if (n % block_lenght == 0) {
        data[n].second = 0;
    } else {
        data[n].second = data[n - 1].second + data[n - 1].first;
    }
    
    int q;
    std::cin >> q;
    for (int j = 0; j < q; ++j) {
        std::string temp;
        std::cin >> temp;
        if (temp == "Add") {
            int i;
            int64_t x;
            std::cin >> i >> x;
            Add(data, i, x, block_lenght);
        } else {
            int l, r;
            std::cin >> l >> r;
            int64_t result = FindSum(data, l, r, block_lenght);
            std::cout << result << '\n';
        }
    }
    return 0;
}
