#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int N, K;
  cin >>N>>K;
  vector<long long> arr(N);
  for(int i=0;i<N;i++)
  cin >>arr[i];
  
  sort(arr.begin(),arr.end());
  long long cnt=0;
  vector<long long> length;
  for(int i=0;i<N-1;i++)
  length.push_back(arr[i+1]-arr[i]);
  sort(length.begin(),length.end());
  for (int i = 0; i < N - K; i++)
    cnt += length[i];

  cout <<cnt;
  
  
  
}