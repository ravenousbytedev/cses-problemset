#include <ios>
#include <iostream>

constexpr unsigned long long mod = 1e9 + 7;

unsigned long long pow(unsigned long long x, unsigned long long n) {
    if (n == 0) {
        return 1;
    }
    x %= mod;
    unsigned long long y = pow(x, n / 2);
    y = y * y % mod;
    if (n % 2 == 1) {
        y = y * x % mod;
    }
    return y;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned long long n;
    std::cin >> n;
    if (n % 2 == 1) {
        std::cout << "0\n";
        return 0;
    }
    n /= 2;
    unsigned long long num = 1;
    for (unsigned long long i = n + 1; i <= 2 * n; ++i) {
        num = num * i % mod;
    }
    unsigned long long denom = 1;
    for (unsigned long long i = 2; i <= n + 1; ++i) {
        denom = denom * i % mod;
    }
    std::cout << num * pow(denom, mod - 2) % mod << '\n';
    return 0;
}
