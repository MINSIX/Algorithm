#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int N;
    map<int,int> mm;
    cin >>N;
    int a;
    for(int i=0;i<N;i++){
        cin >>a;
        mm[a]++;
    }
    cin >> N;
    cout <<mm[N];
    
    
}