#include<bits/stdc++.h>

using namespace std;

int main(){
  
  
  int a,b,c,d,e,f;
  cin >> a>>b>>c>>d;
  
  cin >> e>>f;
  
  cout<<a+b+c+d+e+f-min({a,b,c,d})-min(e,f);
  
}