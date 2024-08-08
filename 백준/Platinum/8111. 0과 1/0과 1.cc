#include<bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vector<bool>visited(N+1,false);
    queue<pair<int,string>>q;
    q.push({1,"1"});
    string current;
    while(!q.empty()){
      int now=q.front().first;
      string s=q.front().second;
      q.pop();
      if(s.length()>100){
        current="BRAK";
        break;
      }
      
      if((now*10+1)%N==0){
        current=s+"1";
        break;
      }
      if((now*10)%N==0){
        current=s+"0";
        break;
      }
      if(!visited[(now*10+1)%N])
      {      q.push({(now*10+1)%N,s+"1"});
        visited[(now*10+1)%N]=true;
        
      }
      
          if(!visited[(now*10)%N])
  {
      q.push({(now*10)%N,s+"0"});
   visited[(now*10)%N]=true;
    
  } }
    
    cout << current<<"\n";
    
  }
}