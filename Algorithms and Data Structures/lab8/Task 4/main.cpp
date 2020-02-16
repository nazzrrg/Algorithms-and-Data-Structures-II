#include <iostream>
#include <vector>

const int SIZE = 1e5 + 10;
std::vector<int> adj[SIZE];
int cmp[SIZE];
bool usd[SIZE];

int n,m;
int f,s;
void input() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &f, &s);
        --f;
        --s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
}
void dfs(int cur) {
    usd[cur] = true;
    for (int i = 0; i < adj[cur].size(); ++i) {
        int nxt = adj[cur][i];
        if (!usd[nxt]) {
            cmp[nxt] = cmp[cur];
            dfs(nxt);
        }
    }
}

int main() {
    freopen("components.in","r",stdin);
    freopen("components.out","w",stdout);

    input();

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!usd[i]) {
            ++cnt;
            cmp[i] = cnt;
            dfs(i);
        }
    }

    std::cout << cnt << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << cmp[i] << ' ';
    }
    return 0;
}