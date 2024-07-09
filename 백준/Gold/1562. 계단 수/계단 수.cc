#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000000;
long long dp[101][10][4] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    int N;
    cin >> N;
    long long cnt = 0;
  
    for(int i = 1; i <= 9; i++) {
        dp[1][i][2*(i==9)] = 1;
    }
  
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k < 4; k++) {
              
                  if(j-1>=0)
                    dp[i][j-1][k|(j==1)] +=dp[i-1][j][k] % MOD;
                
                if(j+1 <= 9) {
                    dp[i][j+1][k|2*(j==8)]+= dp[i-1][j][k] % MOD;
                }
            }
        }
    }
  
    for(int i = 0; i <= 9; i++) {
        cnt += dp[N][i][3] ;
        cnt%=MOD;
    }
  
    cout << cnt;
    return 0;
}