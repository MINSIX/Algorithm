#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<pair<int,int>>arr(4);
  for(int i=0;i<4;i++){
    cin >>arr[i].first>>arr[i].second;
  }

  
  int cnt=0;
  int now=0;
  for(int i=0;i<4;i++){
    now=max(now-arr[i].first,0);
    now+=arr[i].second;
    cnt=max(cnt,now);
    
    
  }
  cout << cnt;
  
  
}