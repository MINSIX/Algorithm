#include<bits/stdc++.h>
using namespace std;


int main(){
   
 string s1;
  string s2;
 while(getline(cin,s1),getline(cin,s2)){
   vector<int>arr(26,0);
   for(int i=0;i<s1.size();i++){
     arr[s1[i]-'a']++;
   }
   sort(s2.begin(),s2.end());
   
   for(int i=0;i<s2.size();i++){
     if(arr[s2[i]-'a']>0)
     {
       arr[s2[i]-'a']--;
       cout<<s2[i];
   }}
   cout<<"\n";
 }
 
 
 
}