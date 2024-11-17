#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> bear(3);
    cin >> bear[0] >>bear[1]>>bear[2];
    sort(bear.begin(),bear.end());
    cout << bear[1];
}