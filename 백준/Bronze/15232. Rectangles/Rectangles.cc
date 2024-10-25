#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a>>b;
    int t=b;
    while(a--){
        b=t;
        while(b--)
          {  cout<<"*";
        }cout<<"\n";
    }
 }