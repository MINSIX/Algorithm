#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  vector<int> arr(N);
  vector<int> mm(N);
  for(int i=0;i<N;i++)
  {cin >>arr[i];
  if(i!=0)
  mm[i]+=mm[i-1];
  mm[i]+=arr[i];
  }
  long long cnt=0;

  for(int i=0;i<N;i++){
    cnt+=arr[i]*(mm[N-1]-mm[i]);
  }

  cout <<cnt;
  
}