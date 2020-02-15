#include <iostream>
#include <vector>

int main() {
    std::freopen("input.txt", "r", stdin);
    std::freopen("output.txt", "w", stdout);

    uint16_t n;
    std::cin >> n;
    std::vector<std::vector<uint16_t>> matrix(n);
    for (auto& v : matrix) {
        v.resize(n);
        for (auto& c : v) {
            std::cin >> c;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((matrix[i][j] != matrix[j][i]) || (matrix[j][j] == 1)) {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "YES" << std::endl;
    return 0;
}
