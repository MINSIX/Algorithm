#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt=0;
    int a=0;
    int b=5;
    while(b--){
        cin >> a;
        if(a<40)
            cnt+=40;
        else
            cnt+=a;
    }
    cout << cnt/5;
}