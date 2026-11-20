#include <ios>
#include <iostream>
#include <vector>

constexpr unsigned long long mod = 1e9 + 7, a_max = 1e6;

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

unsigned long long solve(
    unsigned long long a,
    unsigned long long b,
    std::vector<unsigned long long> &fact
) {
    return fact[a] * pow(fact[b], mod - 2) % mod * pow(fact[a - b], mod - 2) % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int n;
    std::cin >> n;
    unsigned long long a, b;
    std::vector<unsigned long long> fact(a_max + 1, 1);
    for (a = 2; a <= a_max; ++a) {
        fact[a] = fact[a - 1] * a % mod;
    }
    while (n-- > 0) {
        std::cin >> a >> b;
        std::cout << solve(a, b, fact) << '\n';
    }
    return 0;
}
