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
        matrix[--t1][--t2]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] + matrix[j][i] > 1) {
                std::cout << "YES" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "NO" << std::endl;

    return 0;
}
