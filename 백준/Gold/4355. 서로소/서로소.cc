#include<bits/stdc++.h>
using namespace std;


long long seoroso(long long N){
  long long cnt=N;
  if(N==1)
  return 0;
  for(int i=2;i*i<=N;i++){
    if(N%i==0)
      cnt=cnt/i*(i-1);
    while(N%i==0)
    N/=i;
    
  }
  if(N==1)
  return cnt;
  else
  return cnt/N*(N-1);
  
  
  
}

int main(){
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 
 long long N;
 cin >> N;
 
 while(N!=0){
   

   
   
   cout << seoroso(N)<<"\n";
   
   cin >> N;
 }
 
  
  
  
  
  
}