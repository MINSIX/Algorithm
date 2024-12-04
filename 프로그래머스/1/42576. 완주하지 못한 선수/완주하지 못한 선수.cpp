#include<bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> arr;
    for(int i=0;i<participant.size();i++){
        arr[participant[i]]++;
    }
    for(int i=0;i<completion.size();i++){
        arr[completion[i]]--;
    }
    for(int i=0;i<participant.size();i++){
     if(arr[participant[i]])
         return participant[i];
    }
    
}