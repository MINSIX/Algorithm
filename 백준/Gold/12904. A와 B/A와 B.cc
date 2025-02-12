#include<bits/stdc++.h>

using namespace std;

int main(){
  
  string S,T;
  cin >>S>>T;
  
  while(S.size()<T.size()){
    char lastChar = T.back(); 
    T.pop_back();
    if(lastChar=='B')
    reverse(T.begin(),T.end());
    
  
    
  }
    cout << (S == T ? 1 : 0) ;
  
  
}