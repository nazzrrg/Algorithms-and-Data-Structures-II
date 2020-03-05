#include <iostream>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<int> color;
std::vector<bool> used;


void dfs(int i) {
    used[i] = true;
    if (adj[i].empty()) {
        color[i] = 0;
        return;
    }
    for (auto item : adj[i]) {
        if (!used[item]) {
            dfs(item);
        }

        if (!color[i] && !color[item]) {
            color[i] = 1;
        }
    }
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    int n, m, s;
    std::cin >> n >> m >> s;
    adj.resize(n);
    color.assign(n, 0);
    used.assign(n, false);
    --s;

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        adj[--a].push_back(--b);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    if (color[s] == 1) {
        std::cout << "First player wins";
    } else {
        std::cout << "Second player wins";
    }

    return 0;
}
