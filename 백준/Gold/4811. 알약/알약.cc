#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

long long ev[31][31];


long long dp(int W, int H) {
    if (W == 0 && H == 0)return 1;
    if (W < 0 || H < 0)return 0;

    long long& ref = ev[W][H];

    if (ref != -1)
        return ref;
    return ref = (dp(W - 1, H + 1) + dp(W, H - 1));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 31; j++)
            ev[i][j] = -1;
    dp(30 - 1, 1);
    cin >> a;
    while (a != 0) {
        cout <<ev[a-1][1] << endl;
        cin >> a;
    }

    return 0;
}
