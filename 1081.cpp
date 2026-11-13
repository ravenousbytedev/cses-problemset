#include <ios>
#include <iostream>
#include <vector>

constexpr unsigned int xi_max = 1e6;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int n;
    std::cin >> n;
    unsigned int xi;
    std::vector<unsigned int> count(xi_max + 1);
    while (n-- > 0) {
        std::cin >> xi;
        ++count[xi];
    }
    unsigned int multiples;
    for (xi = xi_max; xi > 0; --xi) {
        multiples = 0;
        for (unsigned int xj = xi; xj <= xi_max; xj += xi) {
            multiples += count[xj];
        }
        if (multiples >= 2) {
            std::cout << xi << '\n';
            break;
        }
    }
    return 0;
}
