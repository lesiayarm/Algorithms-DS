#include <iostream>
#include <vector>
#include <cstdint>
#include <limits>
#include <fstream>

struct Item {
    int64_t node;
    int64_t left;
    int64_t right;
};

int main() {
    int n;
    std::ifstream cin("bst.in");
    std::ofstream cout("bst.out");
    cin >> n;
    std::vector<Item> data(n);
    if (n == 0) {
        cout << "YES";
        return 0;
    }
    cin >> data[0].node;
    data[0].left = std::numeric_limits<int64_t>::min();
    data[0].right = std::numeric_limits<int64_t>::max();
    for (int i = 1; i < n; ++i) {
        int number, str;
        char s;
        cin >> number >> str >> s;
        Item temp = data[str - 1];
        data[i].node = number;
        if (s == 'L') {
            data[i].left = temp.left;
            data[i].right = temp.node - 1;
            if (number < data[i].left || number > data[i].right) {
                cout << "NO";
                return 0;
            }
        } else {
            data[i].left = temp.node;
            data[i].right = temp.right;
            if (number < data[i].left || number > data[i].right) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}
