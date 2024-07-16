#include<bits/stdc++.h>
using namespace std;
bool cmp(string& a, string &b){
  return a+b>b+a;
  
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int N;
  cin >> N;
  vector<string> arr(N);
  for(int i=0;i<N;i++){
    cin >> arr[i];
  }
  
  sort(arr.begin(),arr.end(),cmp);
  
  
  if(arr[0][0]-'0'==0){
    cout << 0;
    return 0;
  }
  for(int i=0;i<N;i++){
    cout << arr[i];

    
  }
  
  
  
  
}