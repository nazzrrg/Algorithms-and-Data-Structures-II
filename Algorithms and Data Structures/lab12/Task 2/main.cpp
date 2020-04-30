#include <iostream>
#include <vector>

using namespace std;

struct edge {
    bool exists;
    int c;
};

int t;
vector<bool> used;
vector<vector<edge>> graph;

int dfs (int u, int Cmin) {
    if (u == t) return Cmin;
    used[u] = true;
    for (int i = 0; i < 3000; i++) {
        if (graph[u][i].exists) {//edge exists
            edge e = graph[u][i];
            if (!used[i] && e.c > 0) {
                int delta = dfs(i, min(Cmin, e.c));
                if (delta > 0) {
                    graph[u][i].c = graph[u][i].c - delta;
                    graph[i][u].c = graph[i][u].c + delta;
                    return delta;
                }
            }
        }
    }
    return 0;
}


int main() {
    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);
    int a, b, m;
    cin >> a >> b >> m;
    t = 1000;
    graph.assign(3000, vector<edge>(3000, {false, 0}));
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        to += 200;
        graph[0][from] = {true, 1};
        graph[from][to].exists = true;
        graph[to][from].exists = true; // if no back edge in input c stays == 0
        graph[to][1000] = {true, 1};
        graph[from][to].c += 1;
    }

    long long df = 1;
    long long flow = 0;
    while (df > 0) {
        used.assign(3000, false);
        df = dfs(0, INT32_MAX);
        flow += df;
    }

    cout << flow;

    return 0;
}
