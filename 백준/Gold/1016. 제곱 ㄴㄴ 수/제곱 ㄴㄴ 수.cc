#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b;
  cin >>a>>b;
  vector<bool> arr(b-a+1,false);  
  for(long long i=2;i*i<=b;i++){
    long long now=i*i;
    
    long long st=(a+now-1)/now*now;
    
    for(long long j=st;j<=b;j+=now)
    arr[j-a]=true;
    
    
  }
  
  long long cnt=0;
  for(long long i=0;i<b-a+1;i++)
  if(!arr[i])
  cnt++;
  
  
  cout<<cnt;
}