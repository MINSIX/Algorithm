#include<bits/stdc++.h>

using namespace std;
int main(){
  
  
  
  int X;
  cin >> X;
   
  int now=1;
  while(now<X){
    X-=now;
    now++;

  }
  if(now%2==1)
  cout<< now+1-X<<"/"<<X;
  else
  cout << X<<"/"<<now+1-X;
  
  
  
}