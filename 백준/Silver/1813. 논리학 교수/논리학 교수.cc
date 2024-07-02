#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    map<int,int>arr;
    int a;
    for(int i=0;i<N;i++){
        cin >>a;
        arr[a]++;
    }
    for(int i=N;i>=0;i--){
        if(arr[i]==i)
        {       cout << i;
            return 0;
    }
    }
        cout << -1;
  
    return 0;
    
}