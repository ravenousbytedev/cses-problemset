#include <array>
#include <ios>
#include <iostream>
#include <vector>

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
    unsigned long long n = 0;
    char ch;
    std::array<unsigned long long, 26> counts {};
    while ((ch = std::cin.get()) != '\n') {
        ++counts[ch - 'a'];
        ++n;
    }
    std::vector<unsigned long long> fact(n + 1, 1);
    for (unsigned long long i = 2; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % mod;
    }
    unsigned long long result = fact[n];
    for (unsigned long long count : counts) {
        result = result * pow(fact[count], mod - 2) % mod;
    }
    std::cout << result << '\n';
    return 0;
}
