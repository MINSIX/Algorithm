#include<bits/stdc++.h>
using namespace std;

int main(){
  
  long long X,K;
  cin >> X>>K;
  
  long long Y=0;
  int idx=0;
  for(int i=0;i<65;i++){
    if((X>>i)&1LL)continue;
    if((K>>idx)&1LL)
    Y|=(1LL<<i);
    idx++;
  }
  cout << Y;
  
}