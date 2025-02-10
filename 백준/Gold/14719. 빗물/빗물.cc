#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N,M;
  cin >> N >>M;
  
  vector<int> arr(M);
  for(int i=0;i<M;i++)
  cin >>arr[i];
  
  int cnt=0;
  for(int i=1;i<M-1;i++){
    int left=0,right=0;
    for(int j=0;j<i;j++)
    left=max(left,arr[j]);
    for(int j=M-1;j>i;j--)
    right=max(right,arr[j]);
    cnt+=max(0, min(left,right)-arr[i]);
  }
  
  
  cout <<cnt;
  
}