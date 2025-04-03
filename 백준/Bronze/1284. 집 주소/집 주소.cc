#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string s;
  cin >> s;
  while(s!="0"){
  int cnt=0;
  cnt+=s.size()+1;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='1')
    cnt+=2;
    else if(s[i]=='0')
    cnt+=4;
    else
    cnt+=3;
  
  }  
  cout << cnt<<"\n";
  cin >>s;
    
  }
}