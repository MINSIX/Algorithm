#include<bits/stdc++.h>
using namespace std;

int dy[3]={-1,0,1};

int main(){
 
  int N,M;
  cin >> N >>M;
  vector<vector<int>>arr(N,vector<int>(M));
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >>arr[i][j];
    }
  }
  vector<vector<vector<int>>>dp(N,vector<vector<int>>(M,vector<int>(3,1e9)));
  for(int i=0;i<M;i++)
  for(int j=0;j<3;j++)
  dp[0][i][j]=arr[0][i];
 
  int cnt=1e9; 
  for(int i=0;i<N-1;i++){
    for(int j=0;j<M;j++){
      for(int k=0;k<3;k++){
        if (dp[i][j][k] == 1e9) continue;

        
        for(int l=0;l<3;l++){
          if(k==l)
          continue;
        int xx=i+1;
        int yy=j+dy[l];
        
        if(xx<0||yy<0||xx>=N||yy>=M)
        continue;
       
          
          dp[xx][yy][l]=min(dp[i][j][k]+arr[xx][yy],dp[xx][yy][l]);
          
        }
      }
    }
  }
  for(int i=0;i<M;i++){
    cnt=min(cnt,dp[N-1][i][0]);
    cnt=min(cnt,dp[N-1][i][1]);
    cnt=min(cnt,dp[N-1][i][2]);
  }
  
  cout <<cnt;
  
}