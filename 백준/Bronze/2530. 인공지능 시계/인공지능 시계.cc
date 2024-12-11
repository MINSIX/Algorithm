#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int a,b,c;
  cin >> a>>b>>c;
  int d;
  cin >>d;
  
  if(d>=3600){
    a+=d/3600;
   d%=3600; 
  }
  if(d>=60){
    b+=d/60;
    d%=60;
  }
  c+=d;
  if(c>=60){
    b++;
    c-=60;
  }
  if(b>=60){
    a++;
    b-=60;
  }
  if(a>=24){
    a%=24;
  }
  cout << a << " "<< b<<" "<<c;
  
  
}