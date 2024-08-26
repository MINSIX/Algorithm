#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >>N>>K;
  vector<int>arr(N);
  for(int i=0;i<N;i++)
  cin >>arr[i];
  
  sort(arr.begin(),arr.end());
  
  
  vector<long long>dp(K+1,0);
  
  dp[0]=1;

  for(int j=0;j<N;j++){
   for(int i=arr[j];i<=K;i++){
      dp[i] += dp[i - arr[j]];
    }

  }
  
  cout <<dp[K];
}