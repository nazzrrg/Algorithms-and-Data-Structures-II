#include <iostream>
#include <vector>

using namespace std;

const int64_t INF = 8e18;

struct edge {
    int from, to;
    int64_t cost;
    edge(int from, int to, int64_t cost) : from(from), to(to), cost(cost) {};
    edge() = default;
};

void dfs(int i, vector<vector<int>>& g, vector<bool>& used) {
    used[i] = true;
    for (auto to : g[i]) {
        if (!used[to])
            dfs(to, g, used);
    }
}

void ford(vector<edge>& e, int v, int n, int m, vector<vector<int>>& g) {
    vector<int64_t> d (n, INF);
    d[v] = 0;
    vector<int> p (n, -1);
    int x = -1;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (auto &ee : e) {
            if (d[ee.from] < INF)
                if (d[ee.to] > d[ee.from] + ee.cost) {
                    d[ee.to] = max(-INF, d[ee.from] + ee.cost); // от переполнения вниз
                    p[ee.to] = ee.from;
                    x = ee.to;
                }
        }
    }

    vector<bool> used(n, false);

    if (x != -1) {
        for (int i = 0; i < n; ++i)
            x = p[x]; // так мы точно упремся в цикл в силу того что просматриваем все ребра
        dfs(x, g, used); // обойдем цикл
    }
    for (int i = 0; i < n; ++i) {
        if(used[i]) {
            cout << '-' << endl;
        } else if (d[i] == INF) {
            cout << '*' << endl;
        } else {
            cout << d[i] << endl;
        }
    }
}

int main() {
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    int n, m, s;
    cin >> n >> m >> s;
    vector<edge> e;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i){
        int from, to;
        int64_t cost;
        cin >> from >> to >> cost;
        e.emplace_back(--from, --to, cost);
        g[from].emplace_back(to);
    }

    ford(e, --s, n, m, g);

    return 0;
}
