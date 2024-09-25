#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,m;
    cin >>n>>m;
    int a;
    queue<int>q;
    for(int i=0;i<n;i++){
        cin >>a;
        if(a<m)
            q.push(a);
    }
    while(!q.empty()){
        cout <<q.front()<<" ";
        q.pop();
    }
}