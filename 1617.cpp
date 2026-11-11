#include <ios>
#include <iostream>

constexpr unsigned long long mod = 1e9 + 7;

unsigned long long solve(unsigned long long n) {
    if (n == 0) {
        return 1;
    }
    unsigned long long result = solve(n / 2);
    result = result * result % mod;
    if (n % 2 == 1) {
        result *= 2;
    }
    return result % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned long long n;
    std::cin >> n;
    std::cout << solve(n) << '\n';
    return 0;
}
