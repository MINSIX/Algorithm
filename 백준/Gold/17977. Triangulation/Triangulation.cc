#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int dp[1000001];
    dp[3] = 0;
    dp[4] = 1;

    for (int i = 5; i <= N; i++)
        dp[i] = dp[(i + 1) / 2] + 2;
   

    cout << dp[N];
        return 0;
}
