#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N,K;
  cin >> N >> K;
  
  string s;
  cin >> s;
  stack<char> arr;
  int cnt=0;
  for(int i=0;i<N;i++){
    while(!arr.empty()&&arr.top()<s[i]&&cnt<K)
      {
        cnt++;
        arr.pop();
       
      }
      arr.push(s[i]);
    
  }
  while(cnt<K){
    arr.pop();
    cnt++;
  }
  stack<char>arr2;
  while(!arr.empty()){
    arr2.push(arr.top());
    arr.pop();
  }
  while(!arr2.empty()){
    cout<<arr2.top();
    arr2.pop();
  }
  
}