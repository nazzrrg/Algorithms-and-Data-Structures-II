#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int from, to;
    int64_t c, f;
    edge (int from_, int to_, int64_t c_, int64_t f_) : from(from_), to(to_), c(c_), f(f_) {};
};

int t, cc = 1;
vector<int> buffer;
vector<vector<int>> bufferBuffer;
vector<int> depthBuffer;
vector<int> used;
vector<edge> edges;
vector<vector<int>> vertexEdge; //numbers of edges FROM vertex

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

int dfs2 (int v, int64_t Cmin) {
    if (v == t) {
        return Cmin;
    }
    used[v] = cc;
    for (auto it : vertexEdge[v]) { // numbers of edges from v
        if (used[edges[it].to] != cc && edges[it].f > 0) {
            buffer.push_back(it/2);
            int delta = dfs2(edges[it].to, min(Cmin, edges[it].f));
            if (delta > 0) {
                if (it % 2 == 0) {
                    edges[it].f -= delta;
                    edges[it - 1].f += delta;
                } else {
                    edges[it].f -= delta;
                    edges[it + 1].f += delta;
                }
                return delta;
            }
        }
    }
    buffer.pop_back();
    return 0;
}


int main() {
    freopen("decomposition.in", "r", stdin);
    freopen("decomposition.out", "w", stdout);
    int m;
    cin >> t >> m;
    t--;
    used.assign(2*m, 0);
    edges.assign(2 * m + 2, edge{-1,-1,-1,-1});
    vertexEdge.resize(2 * m);
    for (int i = 1; i <= m; ++i) {
        int from, to;
        int64_t c;
        cin >> from >> to >> c;
        --from; --to;
        vertexEdge[from].push_back(i * 2); // forward edge
        edges[i * 2] = {from, to, c, 0}; // even == forward
        vertexEdge[to].push_back(i * 2 - 1); // backward edge
        edges[i * 2 - 1] = {to, from, 0, 0}; // uneven == backward
    }
    used.assign(2 * m, false);
    long long df, flow = 0;
    while ((df = dfs1(0, INT64_MAX)) > 0) {
        cc++;
        flow += df;
    }

    int count=0;
    while (flow > 0) {
        count++;
        cc++;
        buffer.clear();
        df = dfs2(0, INT64_MAX);
        flow -= df;
        depthBuffer.push_back(df);
        bufferBuffer.push_back(buffer);
    }

    cout << count << endl;
    for (int i = 0; i < count; i++) {
        cout << depthBuffer[i] << ' ' << bufferBuffer[i].size() << ' ';
        for (auto item : bufferBuffer[i]) {
            cout << item << ' ';
        }
        cout << endl;
    }


    return 0;
}
/*
4 5
1 2 1
1 3 2
3 2 1
2 4 2
3 4 1

 3
 *
6 9
1 2 10
1 3 10
2 3 2
2 4 4
2 5 8
3 5 9
5 4 6
4 6 10
5 6 10

 19
 *
6 10
1 2 16
1 3 13
2 3 10
2 4 12
3 2 4
3 5 14
4 3 9
4 6 20
5 4 7
5 6 4

 25
*/