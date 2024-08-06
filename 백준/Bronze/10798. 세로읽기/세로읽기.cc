#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string>s(5);
    int lenmax=0;
    for(int i=0;i<5;i++)
       { 
         cin >>s[i];
         int len=s[i].length();
        lenmax=max(lenmax,len);
         
       }for(int i=0;i<lenmax;i++){
        for(int j=0;j<5;j++){
            if(s[j].size()<=i)
                continue;
            cout<<s[j][i];
            
            
        }

    }
    
    
} 