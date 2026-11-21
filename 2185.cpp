#include <array>
#include <bitset>
#include <ios>
#include <iostream>

constexpr unsigned int k_max = 20;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned long long n;
    unsigned int k;
    std::cin >> n >> k;
    std::array<unsigned long long, k_max> a;
    for (unsigned int i = 0; i < k; ++i) {
        std::cin >> a[i];
    }
    unsigned long long result = 0, divisor;
    std::bitset<k_max> bitset;
    for (unsigned int bitmask = 1; bitmask < 1U << k; ++bitmask) {
        bitset = bitmask;
        divisor = 1;
        for (unsigned int i = 0; i < k; ++i) {
            if (bitset[i]) {
                if (divisor > n / a[i]) {
                    divisor = n + 1;
                    break;
                }
                divisor *= a[i];
            }
        }
        if (bitset.count() % 2 == 1) {
            result += n / divisor;
        } else {
            result -= n / divisor;
        }
    }
    std::cout << result << '\n';
    return 0;
}
