#include <iostream>
#include <stack>
#include <vector>

void dfs(int x, int n, std::vector<std::vector<int>> &graph, std::vector<int> &color, std::stack<int> &sort) {
    color[x] = 1;

    for (auto i : graph[x]) {
        if (color[i] == 0)
            dfs(i, n, graph, color, sort);
    }
    color[x] = 2;
    sort.push(x);
}

int main() {
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[--a].push_back(--b);
    }
    std::vector<int> color(n, 0);

    std::stack<int> sort;

    for (int i = 0; i < n; i++)
        if (color[i] != 2)
            dfs(i, n, graph, color, sort);

    bool flag = false;
    int x = 0, y = 0;

    if (!sort.empty()) {
        x = sort.top();
        sort.pop();
        flag = true;
    }

    while (!sort.empty() && flag) {
        y = sort.top();
        sort.pop();
        flag = false;

        for (auto i : graph[x])
            if (i == y)
                flag = true;
        x = y;
    }

    if (flag)
        std::cout << "YES";
    else
        std::cout << "NO";

    return 0;
}
