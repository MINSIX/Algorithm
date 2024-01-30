#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int N;
int home[1001][3] = { 0, };
int dp[1001][3] = { 0, };

int cal() {

    
    for (int i = 2; i <= N; i++) {
        dp[i][0] = home[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = home[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = home[i][2] + min(dp[i - 1][1], dp[i - 1][0]);

    }

    return min(min(dp[N][0], dp[N][1]), dp[N][2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> home[i][0] >> home[i][1] >> home[i][2];
    }

    dp[1][0] = home[1][0];
    dp[1][1] = home[1][1];
    dp[1][2] = home[1][2];

    int result = cal();

    cout << result << endl;
    return 0;
}



