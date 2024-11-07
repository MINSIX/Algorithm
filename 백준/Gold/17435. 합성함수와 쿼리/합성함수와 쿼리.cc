#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sparse;
vector<int> fx;

int func(int n, int x) {
    for (int i = 0; n > 0; i++) {
        if (n & 1) {
            x = sparse[i][x];
        }
        n >>= 1;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> m;
    fx.resize(m + 1);

    for (int i = 1; i <= m; i++) {
        cin >> fx[i];
    }

    
    sparse.resize(19, vector<int>(m + 1));

    for (int i = 1; i <= m; i++) {
        sparse[0][i] = fx[i];
    }

    for (int k = 1; k < 19; k++) {
        for (int i = 1; i <= m; i++) {
            sparse[k][i] = sparse[k - 1][sparse[k - 1][i]];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int n, x;
        cin >> n >> x;
        cout << func(n, x) << "\n";
    }
}
