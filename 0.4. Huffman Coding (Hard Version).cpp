#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <deque>


void func_min_element(std::deque<int64_t>& deq_1,  std::deque<int64_t>& deq_2, int64_t& min_element) {
    if (deq_1.empty()) {
        min_element = deq_2.front();
        deq_2.pop_front();
        return;
    }
    if (deq_2.empty() || deq_1.front() <= deq_2.front()) {
        min_element = deq_1.front();
        deq_1.pop_front();
        return;
    }
    min_element = deq_2.front();
    deq_2.pop_front();
    return;
}
 
int main()
{
    std::ifstream cin("huffman.in");
    std::ofstream cout("huffman.out");
    int n;
    cin >> n;
    std::vector<int64_t> data(n);
    for (auto& x : data) {
        cin >> x;
    }
    if (n == 2) {
        cout << data[0] + data[1];
        return 0;
    }
    int64_t result = 0;
    std::deque<int64_t> deq_1(data.begin(), data.end());
    std::deque<int64_t> deq_2;
    while (deq_1.size() + deq_2.size() >= 2) {
        int64_t min_1, min_2;
        func_min_element(deq_1, deq_2, min_1);
        func_min_element(deq_1, deq_2, min_2);
        result += min_1 + min_2;
        deq_2.push_back(min_1 + min_2);
    }
    cout << result;
    return 0;
}
