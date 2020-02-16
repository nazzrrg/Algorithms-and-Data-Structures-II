#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::freopen("pathbge1.in", "r", stdin);
    std::freopen("pathbge1.out", "w", stdout);

    int n,m;
    scanf("%d %d", &n, &m);

    std::vector<int> g[n]; // список смежности

    for (int i = 0; i < m; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    std::queue<int> q; // очередь bfs
    q.push(0);
    std::vector<int> d(n, INT32_MAX); // список расстояний
    d[0] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto item : g[v]) {
            if (d[item] == INT32_MAX) {
                d[item] = d[v] + 1;
                q.push(item);
            }
        }
    }

    for (auto item : d) {
        std::cout << item << ' ';
    }

    return 0;
}
