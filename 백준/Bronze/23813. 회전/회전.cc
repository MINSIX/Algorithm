#include<bits/stdc++.h>

using namespace std;

int main(){
  
  
  int N;
  cin >> N;
  vector<int>arr;
  
  while(N>0){
    arr.push_back(N%10);
    N/=10;
  }
  long long t=0;
  long long now=0;
  for(int i=0;i<arr.size();i++){
    t+=arr[i];
  }
  for(int i=0;i<arr.size();i++){
    now+=t*pow(10,i);
  }
  cout <<now;
  
  
}