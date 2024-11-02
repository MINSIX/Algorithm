#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int N;
  cin >> N;
  vector<int> arr(N);
  for(int i=0;i<N;i++)
  cin>>arr[i];
  
  sort(arr.begin(),arr.end());
  
  int result=1;
  for(int i=0;i<N;i++){
    if(arr[i]>result)
    break;
    result+=arr[i];
  }
  
  cout <<result;
}