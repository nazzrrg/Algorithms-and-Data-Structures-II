#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<bool> used;

uint64_t prim() {
    uint64_t res = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        pair<long long, long long> p = q.top();
        q.pop();
        long long fromD = p.first;
        long long fromV = p.second;
        if (used[fromV])
            continue;
        used[fromV] = true;
        res += fromD;
        for (long long i = 0; i < g[fromV].size(); i++) {
            long long toVer = g[fromV][i].first;
            long long toDis = g[fromV][i].second;
            if (!used[toVer])
                q.push(make_pair(toDis, toVer));
        }
    }
    return res;
}

int main() {
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    g.resize(n);
    used.assign(n, false);

    for (int i = 0; i < m; i++) {
        int f, t, w;
        cin >> f >> t >> w;
        g[--f].emplace_back(--t, w);
        g[t].emplace_back(f, w);
    }

    cout << prim();
    return 0;
}
