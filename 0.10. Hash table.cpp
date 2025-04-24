#include <iostream>
#include <fstream>
#include <vector>

int hex(int x, int m, int c, int i) {
    return ((x % m) + c * i) % m;
}
 
int main()
{
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int m, c, n;
    cin >> m >> c >> n;
    std::vector<int> data(m, -1);
    for (int j = 0; j < n; ++j) {
        int x;
        cin >> x;
        int i = 0;
        int temp = hex(x, m, c, i);
        while (data[temp] != -1 && data[temp] != x) {
            ++i;
            temp = hex(x, m, c, i);
        }
        data[temp] = x;
    }
    for (auto& x : data) {
        cout << x << " ";
    }
    return 0;
}
