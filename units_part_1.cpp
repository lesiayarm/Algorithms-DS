#include <iostream>
#include <cstdint>

int64_t MOD = 1000000007;

int64_t fun_fac(int64_t l, int64_t r) {
    int64_t result = 1;
    while (l <= r) {
        result *= l % MOD;
        result %= MOD;
        ++l;
    }
    return result;
}

int64_t bin_pow(int64_t k, int64_t p) { // 2 mod
    if (p == 0) {
        //std::cout << 1 << " " << "p = 0" << " " << p << '\n';
        return 1;
    }
    if (p == 1) {
        //std::cout << k << " " << "p = 1" << " " << p << '\n';
        return k;
    }
    int64_t temp;
    if (p % 2 == 0) {
        temp = bin_pow(k, p / 2) % MOD;
        temp *= temp;
        temp %= MOD;
        //std::cout << temp << " " << "p - четное" << " " << p << '\n';
        return temp;
    }
    temp = bin_pow(k, (p - 1) / 2) % MOD;
    temp *= temp;
    temp %= MOD;
    //std::cout << temp * k % MOD << " " << "p - нечетное" << " " << p << '\n';
    return temp * k % MOD;
}



int main() {
    int64_t n, k;
    std::cin >> n >> k;
    int64_t n_fac = fun_fac(std::max(k, n - k) + 1, n) % MOD;
    int64_t k_fac = fun_fac(2, std::min(k, n - k)) % MOD;
    //std::cout << k_fac << " ";
    int64_t temp = bin_pow(k_fac, MOD - 2) % MOD;
    int64_t result = (n_fac % MOD) * temp % MOD;
    std::cout << result;
    return 0;
}
