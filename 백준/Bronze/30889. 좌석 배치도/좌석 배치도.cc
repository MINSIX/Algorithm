#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>> N;
    vector<vector<char>>arr(11,vector<char>(21,'.'));
    
    vector<string> s(N);
    for(int i=0;i<N;i++)
    cin >> s[i];
    
    for(int i=0;i<N;i++)
    {
        if(s[i].length()==2){
            arr[s[i][0]-'A'][s[i][1]-'0'-1]='o';
        }else{
        arr[s[i][0]-'A'][(s[i][1]-'0')*10+s[i][2]-'0'-1]='o';
        
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++)
            cout<<arr[i][j];
    cout <<endl;}
}