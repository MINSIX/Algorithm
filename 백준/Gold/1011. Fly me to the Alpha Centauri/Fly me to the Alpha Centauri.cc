#include<bits/stdc++.h>
using namespace std;

long long centauri(long long x, long long y){
  long long cnt=0;
  
  long long total = y-x;
  

  long long now=0;
  for(long long i=2;;i++){
    now+=i/2;
    if(now>=total){
     return cnt=i-1;
    }
  }
  
  
  
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while(T--){
    
    long long x,y;
    cin >>x>>y;
    cout << centauri(x,y)<<"\n";
    }
  
  
}