#include<bits/stdc++.h>
using namespace std;

int main(){
    
    long long N,M;
    cin >> N >>M;
    if(N>=M)
    {
        cout << 0;
        return 0;
    }
    long long sum=1;
    while(N>1){
        sum*=N;
        sum%=M;
        N --;
        if(sum==0)
        {
            cout << 0;
            return 0;
        }
    }
    cout << sum;
}