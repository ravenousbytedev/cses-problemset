#include <ios>
#include <iostream>

constexpr unsigned long long mod = 1e9 + 7;

unsigned long long solve(unsigned long long a, unsigned long long b) {
    if (b == 0) {
        return 1;
    }
    a %= mod;
    unsigned long long c = solve(a, b / 2);
    c = c * c % mod;
    if (b % 2 == 1) {
        c = c * a % mod;
    }
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int n;
    std::cin >> n;
    unsigned long long a, b;
    while (n-- > 0) {
        std::cin >> a >> b;
        std::cout << solve(a, b) << '\n';
    }
    return 0;
}
