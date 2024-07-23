#include<bits/stdc++.h>

using namespace std;

int main(){
  long long N;
  cin >> N;
  vector<long long>fibonim(80);
  
  fibonim[0]=1;
  fibonim[1]=1;
  int i=2;
  for(i;i<80;i++){
    fibonim[i]=fibonim[i-2]+fibonim[i-1];
    if(fibonim[i]>N)
    break;
    
  }
  
  for(;i>0;i--){
    if(N==fibonim[i]){
      break;
      
    }
      if(N>fibonim[i]){
        N-=fibonim[i];
        
      }
    
    
  }
  cout << N;
  
  
  
}