#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int>&b){
  if(a.first!=b.first)
  return a.first>b.first;
  
  return a.second>b.second;
  
}


int main(){
  
  int N;
  cin >> N;
  vector<pair<int,int>>arr(N);
  
  vector<int>dp(N,1);
  for(auto &i : arr){
    cin >>i.first>>i.second;
    if(i.first<i.second)swap(i.first,i.second);
    
    
  }
  sort(arr.begin(),arr.end(),cmp);
  int cnt=0;
  for(int i=0;i<N;i++){

    for(int j=i+1;j<N;j++){
      
      if(arr[j].first<=arr[i].first&&arr[j].second<=arr[i].second){
        
        dp[j]=max(dp[j],dp[i]+1);
        cnt=max(cnt,dp[j]);
      }
      
      
    }
  }
  cout << cnt;
}