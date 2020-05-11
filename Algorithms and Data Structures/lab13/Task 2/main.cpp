#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);

    string p, t;

    getline(cin, p);
    getline(cin, t);

    vector<int> pi(p.length());

    pi[0] = 0;
    int l;
    for (l = 1; l < p.length(); l++) {
        int j = pi[l-1];

        while ((j > 0) && p[j]!=p[l]) {
            j = pi[j-1];
        }

        if (p[j]==p[l])
            j++;

        pi[l]=j;
    }


    vector<int> c;
    int j = 0;
    for (int i = 0; i < t.length(); i++) {
        while ((j > 0) && t[i]!=p[j]) {
            j = pi[j-1];
        }
        if (p[j] == t[i])
            j++;

        if (j == l) {
            c.push_back(i-l+1);
        }
    }

    cout << c.size() << endl;
    for (auto i : c) {
        cout << i+1 << ' ';
    }
    return 0;
}
