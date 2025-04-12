#include<bits/stdc++.h>
using namespace std;

int main(){
  
  
  int sum=0;
  int mini=1e9;
  for(int i=0;i<7;i++){
    int a;
    cin >> a;
    
    if(a%2==1){
      sum+=a;
      mini=min(mini,a);
    }
    
    
  }
  if(sum==0)
  cout << -1;
  else
  cout << sum<<"\n"<<mini;
}