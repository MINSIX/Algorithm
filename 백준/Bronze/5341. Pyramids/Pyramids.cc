#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    while(a!=0){
        int sum=0;
        for(int i=1;i<=a;i++)
        {
            sum+=i;
        }
        cout <<sum<<"\n";
        cin >> a; 
    }
    
    
    
}