#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  vector<int> arr(N+1);
  vector<int> dp(N+1);
  for(int i=1;i<=N;i++)
  cin >>arr[i];
  
  int now=0;
  
  for(int i=1;i<=N;i++){
    dp[i]=1;
    for(int j=1;j<=i;j++)
      if(arr[j]<arr[i]&&dp[i]<dp[j]+1)
        dp[i]=dp[j]+1;
  
  now=max(now,dp[i]);
    
  }
  cout << N-now;
}