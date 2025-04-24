#include <iostream>
#include <cstdint>
#include <vector>

struct place {
    int num = -1;
    int64_t max_sum = -1;
    int best_way = -1;
};


int main()
{
    int  n;
    std::cin >> n;
    std::vector<place> data(n);
    for (auto& x : data) {
        std::cin >> x.num;
    }
    if (n == 2) {
        std::cout << -1;
        return 0;
    }

    data[0].max_sum = data[0].num;
    data[0].best_way = -1;
    data[2].max_sum = data[0].max_sum + data[2].num;
    data[2].best_way = 0;
    for (int i = 3; i < data.size(); ++i) {
        if (data[i - 2].max_sum >= data[i - 3].max_sum) {
            if (data[i - 2].max_sum == -1) {
                continue;
            }
            data[i].best_way = i - 2;
            data[i].max_sum = data[i - 2].max_sum + data[i].num;
            continue;
        }
        data[i].best_way = i - 3;
        data[i].max_sum = data[i - 3].max_sum + data[i].num;
    }
    std::cout << data.back().max_sum << '\n';
    int temp = data.back().best_way;
    std::vector<int> result;
    result.push_back(data.size());
    while (temp != -1) {
        result.push_back(temp + 1);
        temp = data[temp].best_way;
    }
    for (int i = result.size() - 1; i >= 0; --i) {
        std::cout << result[i] << " ";
    }
    return 0;
}
