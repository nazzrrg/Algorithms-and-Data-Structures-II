#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> color;

bool dfs(int n, int c) { // номер и какой цвет должен быть
    c %= 2;
    if (color[n] == -1) color[n] = c;
    if (color[n] != c) return false;

    for (auto item : v[n]) {
        if (color[item] == -1) {
            if (!dfs(item, c + 1)) return false;
        }
        if (color[item] == c) return false;
    }
    return true;
}

int main() {
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    v.resize(n);
    color.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        v[--a].push_back(--b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
        if (color[i] == -1) {
            if (!dfs(i, 0)){
                cout << "NO";
                return 0;
            }
        }


    cout << "YES";
    return 0;
}
