#include <iostream>
#include <fstream>
#include <cstdint>
 
int main() {
    int64_t n;
    std::ifstream cin("input.txt");
    cin >> n;
    int64_t counter = 0;
    std::ofstream cout("output.txt");
    while (n > 0) {
        if (n % 2 == 1) {
            cout << counter << '\n';
        }
        n /= 2;
        ++counter;
    }
    return 0;
}
