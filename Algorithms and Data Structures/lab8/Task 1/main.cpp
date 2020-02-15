#include <iostream>
#include <vector>

int main() {
    std::freopen("input.txt", "r", stdin);
    std::freopen("output.txt", "w", stdout);

    uint16_t n,m;
    std::cin >> n >> m;

    std::vector<std::vector<uint8_t>> matrix(n);
    for (auto& v : matrix) {
        v.resize(n);
    }

    for (uint16_t t1, t2, i = 0; i < m; i++) {
        std::cin >> t1 >> t2;
        matrix[--t1][--t2] = 1;
    }

    for (const auto& v : matrix) {
        for (auto a : v) {
            std::cout << int(a) << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
