#include<bits/stdc++.h>
using namespace std;

int main(){
  int INF=987654321;
  int N;
  cin >> N;
  vector<vector<int>> arr(N,vector<int>(N));
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin >> arr[i][j];
  
  vector<vector<int>> dp(N,vector<int>((1<<N),INF));
  
   for(int i=0; i<N; i++){
    dp[0][1<<i] = arr[0][i];
  }

  for(int i=1;i<N;i++){
    for(int j=0; j<(1<<N); j++){
      if(dp[i-1][j] == INF) continue;
       
       for(int c=0; c<N; c++){
        if(j & (1<<c)) continue;
      
        dp[i][j | (1<<c)] = min(dp[i][j | (1<<c)], dp[i-1][j] + arr[i][c]);
      }
    }
  }
  
  cout << dp[N-1][(1<<N)-1];
}
