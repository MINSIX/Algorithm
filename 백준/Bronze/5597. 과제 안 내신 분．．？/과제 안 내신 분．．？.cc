#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<bool>visited(31,false);
  int a;
  for(int i=0;i<28;i++){
    cin >>a;
    visited[a]=true;
  }
  
  for(int i=1;i<=30;i++)
  {
    if(!visited[i])
    cout<< i<<"\n";
    
  }
  
  
}