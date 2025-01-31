#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int>dp(10001,1e9);

int main(){
  
  int N,K;
  cin >> N >>K;
  arr.resize(N);
  for(int i=0;i<N;i++)
  {cin >> arr[i];
 
    
  }
  dp[0]=0;
  
  sort(arr.begin(),arr.end());
  
  for(int i=0;i<N;i++){
    for(int j=arr[i];j<=K;j++){
      dp[j]=min(dp[j-arr[i]]+1,dp[j]);
      
    }
  }
  if(dp[K]==1e9)
  cout <<-1;
  else
  cout <<dp[K];
  
}