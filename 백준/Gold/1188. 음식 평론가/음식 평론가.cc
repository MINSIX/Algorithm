#include<bits/stdc++.h>
using namespace std;

int GND(int n,int m){
  
  if(m==0)return n;
  return GND(m,n%m);
  
  
  
  
}


int main(){
  
  int N,M;
  cin >> N >> M;
  

  cout << M - GND(N,M);
  
}