#include <iostream>
#include <vector>

void dfs1(std::vector <std::vector<int> > &a, std::vector <bool> &used, std::vector <int> &ans, int v){
    used[v] = true;
    for (int i = 0; i < a[v].size(); i++){
        if (!used[a[v][i]]){
            dfs1(a, used, ans, a[v][i]);
        }
    }
    ans.push_back(v);
}

void dfs2(std::vector <std::vector <int> > &a_t, std::vector <int> &comp, int v, int num){
    comp[v] = num;
    for (int i = 0; i < a_t[v].size(); i++){
        if (comp[a_t[v][i]] == -1){
            dfs2(a_t, comp, a_t[v][i], num);
        }
    }
}

int main()
{
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    int n, m, x, y;
    std::cin >> n >> m;
    std::vector <std::vector <int> > a(n, std::vector <int> ());
    std::vector <std::vector <int> > a_t(n, std::vector <int> ());
    std::vector <bool> used(n, false);
    for (int i = 0; i < m; i++){
        std::cin >> x >> y;
        a[--x].push_back(--y);
        a_t[y].push_back(x);
    }
    std::vector <int> ans;
    for (int i = 0; i < n; i++){
        if (!used[i]){
            dfs1(a, used, ans, i);
        }
    }
    std::vector <int> comp(n, -1);
    int num = 1;
    for (int i = ans.size() - 1; i >= 0; i--){
        if (comp[ans[i]] == -1){
            dfs2(a_t, comp, ans[i], num);
            num++;
        }
    }
    std::cout << num - 1 << std::endl;
    for (int i = 0; i < n; i++){
        std::cout << comp[i] << ' ';
    }
    return 0;
}
