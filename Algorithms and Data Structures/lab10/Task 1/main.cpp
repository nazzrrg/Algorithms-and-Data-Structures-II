#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a-1]++;
        v[b-1]++;
    }

    for (auto item : v) {
        cout << item << ' ';
    }

    return 0;
}
