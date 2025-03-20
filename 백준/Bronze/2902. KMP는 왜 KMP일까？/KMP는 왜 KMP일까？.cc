#include<bits/stdc++.h>
using namespace std;

int main(){
 
  string S;
  cin >> S;
  bool check=false;
  for(int i=0;i<S.length();i++){
    
    if(!check)
    {cout << S[i];
      check=true;
      
    }
    if(S[i]=='-')
    check=false;
    
  }
  
  
}