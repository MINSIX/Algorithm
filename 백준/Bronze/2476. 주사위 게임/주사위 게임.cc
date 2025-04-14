#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  int cnt=0;
  for(int i=0;i<N;i++){
    int a,b,c;
    cin >> a>>b>>c;
    int sum=0;
    if(a==b&&b==c){
      sum=10000+a*1000;
    }else if(a!=b&&b!=c&&c!=a){
      sum=max({a,b,c})*100;
    }else{
      if(a==b)
      sum=1000+100*a;
      else if(b==c)
      sum=1000+100*b;
      else
      sum=1000+100*a;
      
    }
    cnt=max(cnt,sum);
    
    
  }
  cout << cnt;
  
}