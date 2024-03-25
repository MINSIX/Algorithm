#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int N;
int home[1001][3] = { 0, };
int dp[1001][3] = { 0, };
int result = INF;
int main() {
    
    cin >> N;
   
    for (int i = 1; i <= N; i++) {
        cin >> home[i][0] >> home[i][1] >> home[i][2];
    }


    for (int rgb = 0; rgb <= 2; rgb++) {

        for (int i = 0; i <= 2; i++)
        {
            if (i == rgb)dp[1][i] = home[1][i];
            else dp[1][i] = INF;
        }

  
        for (int i = 2; i <= N; i++) {

            dp[i][0] = home[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = home[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = home[i][2] + min(dp[i - 1][1], dp[i - 1][0]);

        }

        for (int i = 0; i <= 2; i++)
        {
            if (i == rgb)continue;
            else result = min(result, dp[N][i]);
        }

    }

   cout << result << endl;
    
}



