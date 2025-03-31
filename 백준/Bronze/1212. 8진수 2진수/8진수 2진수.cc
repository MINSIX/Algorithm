#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string nums[8]={"000","001","010","011","100","101","110","111"};
  string S;
  cin >>S;
  cout <<stoi(nums[S[0]-'0']);
  for(int i=1;i<S.length();i++){
    cout << nums[S[i]-'0'];
    
  }
  
}