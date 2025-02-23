#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >>a>>b>>c;
    if(b<max(a,c))
       cout<<"Bus";
    else if(max(a,c)<b)
        cout << "Subway";
    else
        cout<<"Anything";
}