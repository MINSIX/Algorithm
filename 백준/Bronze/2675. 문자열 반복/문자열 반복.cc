#include<bits/stdc++.h>
using namespace std;
int main(){
  
  
  int T;
  cin >> T;
  while(T--){
    int a;
    cin >> a;
    string s;
    cin >>s;
    for(int j=0;j<s.size();j++)
    for(int i=0;i<a;i++){
      cout <<s[j];
    }
    
    cout<<"\n";
  }
}