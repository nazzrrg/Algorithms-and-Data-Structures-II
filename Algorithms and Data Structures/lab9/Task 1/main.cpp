#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> v;
vector<int> color; // 0 - white 1 - grey 2 - black
stack<int> s;

bool dfs(int n) {
    color[n] = 1;
    bool b = true;
    for (auto item : v[n]) {
        if (color[item] == 0) {
             b &= dfs(item);
        } else if (color[item] == 1) {
            return false;
        } else if (color[item] == 2) {
            continue;
        }
    }
    color[n] = 2;
    s.push(n);
    return b;
}


int main() {
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    v.resize(n);
    color.resize(n);

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        v[--a].push_back(--b);
//        v[b].push_back(a);
    }
    bool pos = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            pos &= dfs(i);
        }
    }

    if (pos) {
        while (!s.empty()) {
            cout << s.top() + 1 << ' ';
            s.pop();
        }
    } else {
        cout << -1 << std::endl;
    }



    return 0;
}
