#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int N,M;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int t = 0; t < N; t++) {
        cin >> M;
        vector<vector<int>> home(2, vector<int>(M+1, 0));
        vector<vector<int>> dp(2, vector<int>(M+1, 0));

        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < M; i++) {
                cin >> home[j][i];
            }
        }
        dp[0][0] = home[0][0];
        dp[1][0] = home[1][0];
        if (M == 1)
        {
            cout << max(dp[0][0], dp[1][0]) << endl;
            continue;
        }
        
        dp[0][1] = home[0][1]+home[1][0];
        dp[1][1] = home[1][1]+home[0][0];
        for (int i = 2; i <M; i++) {
            dp[0][i] = home[0][i] + max(dp[1][i - 1], max(dp[0][i - 2],dp[1][i - 2]));
            dp[1][i] = home[1][i] + max(dp[0][i - 1], max(dp[1][i - 2],dp[0][i - 2]));
          
        }

        cout << max(dp[0][M - 1], max(dp[1][M - 1], max(dp[0][M - 2], dp[1][M - 2]))) << endl;

    }


return 0;
}



