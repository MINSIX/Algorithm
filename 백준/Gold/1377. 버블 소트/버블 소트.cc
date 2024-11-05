#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<pair<int,int>>arr;
  int a;
  for(int i=0;i<N;i++)
  {cin >>a;
    
    arr.push_back({a,i});

    
  }
  int cnt=0;
  sort(arr.begin(),arr.end());
  for(int i=0;i<N;i++){
    if(arr[i].second>i)
    cnt=max(cnt,arr[i].second-i);
    
  }
  cout << cnt+1;
}