#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int>arr(N+1);
  vector<int>dp(N+1);
  
  for(int i=1;i<=N;i++){
    cin >> arr[i];
    dp[i]=arr[i];  
  }
  
  
  for(int i=2;i<=N;i++)
  {
    for(int j=1;j<i;j++){
      dp[i]=max(dp[i-j]+arr[j],dp[i]);
    }
  }
  
  cout <<dp[N];
}