#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int x,y;
  cin >> x>>y ;
  
  
  int raw=abs((x-1)/4-(y-1)/4);
  int col=abs((x-1)%4-(y-1)%4);
  cout <<raw+col;
  
  
}