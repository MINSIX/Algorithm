#include<bits/stdc++.h>
using namespace std;

int main(){
  
  
  int N,M;
  cin >> N >> M;
  vector<pair<int,int>> arr;
  int a,b;
  for(int i=0;i<M;i++){
    cin >> a>>b;
    arr.push_back({a,b});
  }
  vector<int> range(N+1);
  for(int i=1;i<=N;i++){
    range[i]=i;
  }
  
  for(auto k : arr){
    int fir=k.first;
    int sec = k.second;
    int mid=(fir+sec+1)/2;
    
    for(int i=0;i<mid-fir;i++){
    swap(range[fir+i],range[sec-i]);
      
    }
    
    
  }
  
  for(int i=1;i<=N;i++)
  cout<<range[i]<<" ";
  
}