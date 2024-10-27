#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long N,K,Q;
  cin >> N>>K>>Q;
  long long x,y;
  for(int i=0;i<Q;i++)
{
  cin >>x>>y;
  long long cnt=0;
  if(K==1)
    cnt =abs(x-y);
  else{

  while(x!=y){
    if(x>y)
      x=(x-2)/K+1;
    else
    y=(y-2)/K+1;
    
    cnt++;
  }

      
    }
  cout<<cnt<<"\n";
  
}  
  
}