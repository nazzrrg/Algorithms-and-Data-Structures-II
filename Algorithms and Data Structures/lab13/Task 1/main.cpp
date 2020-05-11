#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);

    string p, t;

    getline(cin, p);
    getline(cin, t);
    vector<int> c;

    for (int i = 0; i < t.length(); i++) {
        if (t[i] == p[0]) {
            bool flag = true;
            for (int j = 0; j < p.length(); j++) {
                if (p[j]!=t[i+j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                c.push_back(i+1);
            }
        }
    }
    cout << c.size() << endl;
    for (auto i : c) {
        cout << i << ' ';
    }
    return 0;
}
