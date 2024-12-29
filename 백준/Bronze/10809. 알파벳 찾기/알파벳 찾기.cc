#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  vector<int> arr(26,-1);
  for(int i=0;i<s.length();i++){
  if(arr[s[i]-'a']==-1)
  arr[s[i]-'a']=i;
  }
  for(int i=0;i<26;i++)
  cout << arr[i]<<" ";
  
}