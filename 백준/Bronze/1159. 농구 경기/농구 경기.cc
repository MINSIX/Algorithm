#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int>arr(26,0);
  while(N--){
    string s;
    cin >> s;
    
    arr[s[0]-'a']++;
  }
  bool check=false;
  for(int i=0;i<26;i++){
    if(arr[i]>=5)
    {
    char a=i+'a';
    cout <<a;
    check=true;  
    }
    
  }
  if(!check)
  cout << "PREDAJA";
}