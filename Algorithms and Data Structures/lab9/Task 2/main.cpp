#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> color; // 0 - white 1 - grey 2 - black
vector<int> parent;
int s;
int e;

bool dfs(int n) {
    color[n] = 1;
    for (auto item : v[n]) {
        if (color[item] == 0) {
            parent[item] = n;
            if (dfs(item)) return true;
        } else if (color[item] == 1) {
            e = n;
            s = item;
            return true;
        }
    }
    color[n] = 2;
    return false;
}

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    v.resize(n);
    color.resize(n);
    color.assign(n, 0);
    parent.resize(n);
    parent.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        v[--a].push_back(--b);
    }

    s = -1;
    for (int i = 0; i < n; i++) {
        if (dfs(i)) {
            break;
        }
    }

    if (s == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> cycle;
        for (int i = e; i != s; i = parent[i])
            cycle.push_back(i);
        cycle.push_back(s);
        for (size_t i = cycle.size(); i > 0; i--)
            cout << cycle[i - 1] + 1 << ' ';
    }

    return 0;
}
