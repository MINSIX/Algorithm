#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int x1,y1;
  int x2,y2;
  int x3,y3;
  cin >> x1>>y1>>x2>>y2>>x3>>y3;
  
  long long check=x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
  
  if(check<0)
  cout <<-1;
  else if(check>0)
  cout << 1;
  else
  cout <<0;
  
  
}