#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  long long K, N;
  cin >>K >> N;
  
  vector<long long> arr(K);
  for(int i=0;i<K;i++)
  {
    cin>>arr[i];
  }
  
  sort(arr.begin(),arr.end());
  
  long long st=1;
  long long ed = arr[K-1];
  long long mid;
  long long ans;
  while(st<=ed){
    mid = (st+ed)/2;
    long long cnt=0;
    for(int i=0;i<K;i++){
      cnt+=arr[i]/mid;
    }
    if(cnt>=N){
    ans=mid;
    st=mid+1;
    }
    else
    ed=mid-1;
    
  }
  cout << ans;
  
  
  
  
  
}