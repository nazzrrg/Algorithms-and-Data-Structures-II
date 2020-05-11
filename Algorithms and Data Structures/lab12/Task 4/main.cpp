#include <iostream>
#include <vector>

using namespace std;

int n,m,t,s,cc = 1;
struct edge {
    int from, to;
    int64_t c, f;
    edge (int from_, int to_, int64_t c_, int64_t f_) : from(from_), to(to_), c(c_), f(f_) {};
};

vector<int> used;
vector<edge> edges;
vector<vector<int>> vertexEdge;
vector<int> bigL;

int dfs1 (int v, int64_t Cmin) {
    if (v == t) return Cmin;
    used[v] = cc;
    for (auto it : vertexEdge[v]) { // numbers of edges from v
        if (used[edges[it].to] != cc && edges[it].c > edges[it].f) {
            int delta = dfs1(edges[it].to, min(Cmin, edges[it].c - edges[it].f));
            if (delta > 0) {
                if (it % 2 == 0) {
                    edges[it].f += delta;
                    edges[it - 1].f -= delta;
                } else {
                    edges[it].f += delta;
                    edges[it + 1].f -= delta;
                }
                return delta;
            }
        }
    }
    return 0;
}

int64_t maxFlow() {
    used.assign(2 * m, false);
    long long df, flow = 0;
    while ((df = dfs1(s, INT64_MAX)) > 0) {
        cc++;
        flow += df;
    }
    return flow;
}

int main() {
    freopen("circulation.in", "r", stdin);
    freopen("circulation.out", "w", stdout);
    cin >> n >> m;
    t = n + 1;
    s = 0;
    used.assign(n + 2, 0);
    bigL.resize(m + 1);
    edges.assign(6 * (m + 1), edge{-1,-1,-1,-1});
    vertexEdge.resize(n + 2);
    for (int i = 1; i <= m; ++i) {
        int from, to;
        int64_t l, c;
        cin >> from >> to >> l >> c;
        bigL[i] = l; // remember L
        vertexEdge[from].push_back(i * 6);
        edges[i*6] = {from, to, c - l, 0};
        vertexEdge[to].push_back(i * 6 - 1);
        edges[i*6-1] = {to, from, 0, 0};

        vertexEdge[s].push_back(i * 6 - 2);
        edges[i*6-2] = {s, to, l, 0};
        vertexEdge[to].push_back(i * 6 - 3);
        edges[i*6-3] = {to, s, 0, 0};

        vertexEdge[from].push_back(i * 6 - 4);
        edges[i*6-4] = {from, t, l, 0};
        vertexEdge[t].push_back(i * 6 - 5);
        edges[i*6-5] = {t, from, 0, 0};
    }

    maxFlow();

    for (auto item : vertexEdge[0]) {
        if (edges[item].f < edges[item].c) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= m; i++) {
        cout << edges[i * 6].f+bigL[i] << endl;
    }

    return 0;
}
