#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int N;
int home[100001][3];

int dp[2][3];
int dp1[2][3] ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> home[i][0] >> home[i][1] >> home[i][2];
    }
   
    dp[0][0] = home[1][0];
    dp[0][1] = home[1][1];
    dp[0][2] = home[1][2];  
    dp1[0][0] = home[1][0];
    dp1[0][1] = home[1][1];
    dp1[0][2] = home[1][2];

    for (int i = 2; i <= N; i++) {
        if(i%2==0){
        dp[1][0] = home[i][0] + min(dp[0][1], dp[0][0]);
        dp[1][1] = home[i][1] + min(dp[0][0], min(dp[0][2], dp[0][1]));
        dp[1][2] = home[i][2] + min(dp[0][1], dp[0][2]);
        dp1[1][0] = home[i][0] + max(dp1[0][1], dp1[0][0]);
        dp1[1][1] = home[i][1] + max(dp1[0][0], max(dp1[0][2], dp1[0][1]));
        dp1[1][2] = home[i][2] + max(dp1[0][1], dp1[0][2]);
        }
        else {
            dp[0][0] = home[i][0] + min(dp[1][1], dp[1][0]);
            dp[0][1] = home[i][1] + min(dp[1][0], min(dp[1][2], dp[1][1]));
            dp[0][2] = home[i][2] + min(dp[1][1], dp[1][2]);
            dp1[0][0] = home[i][0] + max(dp1[1][1], dp1[1][0]);
            dp1[0][1] = home[i][1] + max(dp1[1][0], max(dp1[1][2], dp1[1][1]));
            dp1[0][2] = home[i][2] + max(dp1[1][1], dp1[1][2]);

        }
    }

    if(N%2==0)
    cout <<max(max(dp1[1][0], dp1[1][1]), dp1[1][2]) << " " << min(min(dp[1][0], dp[1][1]), dp[1][2]) << endl;
    else {
        cout << max(max(dp1[0][0], dp1[0][1]), dp1[0][2]) << " " << min(min(dp[0][0], dp[0][1]), dp[0][2]) << endl;

    }
    return 0;
}



