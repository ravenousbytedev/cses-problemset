#include <ios>
#include <iostream>
#include <vector>

constexpr unsigned long long mod = 1e9 + 7, n_max = 1e6;

unsigned long long solve(unsigned long long n) {
    static std::vector<unsigned long long> memo(n_max + 1, mod);
    memo[0] = 1;
    memo[1] = 0;
    if (memo[n] != mod) {
        return memo[n];
    }
    return (memo[n] = (n - 1) * (solve(n - 1) + solve(n - 2)) % mod);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned long long n;
    std::cin >> n;
    std::cout << solve(n) << '\n';
    return 0;
}
