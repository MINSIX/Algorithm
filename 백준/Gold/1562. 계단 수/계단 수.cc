#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000000;
long long dp[101][10][1024] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }
    
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < 1024; k++) {
                if (j == 0) {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i-1][j+1][k]) % MOD;
                } else if (j == 9) {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i-1][j-1][k]) % MOD;
                } else {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i-1][j-1][k] + dp[i-1][j+1][k]) % MOD;
                }
            }
        }
    }
    
    long long cnt = 0;
    for (int j = 0; j <= 9; j++) {
        cnt = (cnt + dp[N][j][1023]) % MOD;
    }
    
    cout << cnt << endl;
    
    return 0;
}