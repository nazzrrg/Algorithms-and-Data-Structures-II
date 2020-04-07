#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int64_t dj(vector<vector<pair<uint64_t, int>>>& g, int s, int f) { // спасибо хохлу за такие дикие оптимизации
    int n = g.size();
    vector<uint64_t> d (n, INT64_MAX);
    set<pair<uint64_t, int>> ss;
    ss.insert({0, s});
    d[s] = 0;

    while(!ss.empty()) {
        pair<uint64_t, int> v = *ss.begin();
        ss.erase(ss.begin());

        for (auto item : g[v.second]) {
            if (d[item.second] > v.first + item.first) {
                ss.erase({d[item.second], item.second});
                d[item.second] = v.first + item.first;
                ss.insert({d[item.second], item.second});
            }
        }
    }
    return d[f] == INT64_MAX ? -1 : d[f];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
    int n,s,f;
    cin >> n >> s >> f;
    vector<vector<pair<uint64_t, int>>> g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int64_t a;
            cin >> a;
            if (a > 0) {
                g[i].emplace_back(a, j);
            }
        }
    }

    cout << dj(g, --s, --f);

    return 0;
}
