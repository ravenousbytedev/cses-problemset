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
    unsigned long long n, m;
    std::cin >> n >> m;
    unsigned long long fact1 = 1, fact2 = 1, fact3 = 1;
    for (unsigned long long i = 2; i < n + m; ++i) {
        fact1 = fact1 * i % mod;
        if (i < n) {
            fact2 = fact1;
        }
        if (i <= m) {
            fact3 = fact1;
        }
    }
    std::cout
        << fact1 * pow(fact2, mod - 2) % mod * pow(fact3, mod - 2) % mod
        << '\n';
    return 0;
}
