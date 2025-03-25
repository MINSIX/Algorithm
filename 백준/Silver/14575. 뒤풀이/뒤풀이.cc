#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N,T;
  cin >> N >>T;
  
  vector<pair<int,int>> arr(N);
  int left=0,right=0;
  for(int i=0;i<N;i++){
    cin >>arr[i].first >> arr[i].second;
    left+=arr[i].first;
    right+=arr[i].second;
  }
  if(left>T||right<T)
  {
    cout << -1;
    return 0;
  }
  
  int st=0,ed=T;
  while(st<=ed){
    int mid=(st+ed)/2;
    int sum=0;
    
    bool flag=false;
    for(int i=0;i<N;i++){
      if(arr[i].first>mid){
        flag=true;
        break;
      }
      sum+=min(arr[i].second,mid);
    }
    
    if(sum>=T&&!flag)
    ed=mid-1;
    else
    st=mid+1;
    
  }
  
  cout << st;
  
  
  
}