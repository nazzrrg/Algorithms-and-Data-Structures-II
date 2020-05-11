#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    string p, t;

    getline(cin, p);
//    getline(cin, t);

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

    for (auto i : pi) {
        cout << i << ' ';
    }
    return 0;
}
