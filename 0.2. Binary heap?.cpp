#include <iostream>
#include <vector>
#include <fstream>

bool IsHeap(const std::vector<int>& data) {
    size_t size = data.size();
    for (size_t i = 0; i < size; ++i) {
        size_t child = 2 * (i + 1) - 1;
        if (child < size && data[i] > data[child]) {
            return false;
        }
        ++child;
        if (child < size && data[i] > data[child]) {
            return false;
        }
    }
    return true;
}


int main()
{
    int n;
    std::ifstream in("input.txt");
    in >> n;
    std::vector<int> data(n);
    for (auto& x : data) {
        in >> x;
    }
    std::ofstream out("output.txt");
    if (IsHeap(data)) {
        out << "Yes" << '\n';
    }
    else {
        out << "No" << '\n';
    }
    return 0;
}
