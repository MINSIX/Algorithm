#include<bits/stdc++.h>



using namespace std;

int solution(string s) {
    
    stringstream ss(s); 
    string s1;
    int save=0;
    int sum=0;
    while(ss>>s1){
        if(s1=="Z")
        {
            sum-=save;
        }else{
    save=atoi(s1.c_str());
            sum+=save;
        }
        
    }
    int answer = 0;
    answer=sum;
    return answer;
}