#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
   
    unordered_map<string,int> m;
    vector<string> a;
    for(int i=0;i<clothes.size();i++){
        m[clothes[i][1]]++;
        
    }
    long long sum=1;
    for(auto it : m){
        sum*=(it.second+1);
    }
    
    
    sum-=1;
    return sum;
}