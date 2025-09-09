#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int N,M;
  cin>>N>>M;
  
  vector<int> jump(101);
  for(int i=0;i<N;i++){
    int a,b;
    cin >>a>>b;
    jump[a]=b;
  }
  for(int i=0;i<M;i++){
    int a,b;
    cin >>a>>b;
    jump[a]=b;
  }
  
  queue<pair<int,int>> q;
  q.push({1,0});
  vector<bool>visited(101,false);
  visited[1]=true;
  while(!q.empty()){
    
    int now=q.front().first;
    int times=q.front().second;
    visited[now]=true;  
    q.pop();
    if(now==100){
      cout << times;
      return 0;
    }

    for(int i=1;i<=6;i++){
      if(!visited[now+i])
      {
        int next=now+i;
        if(jump[next])
        next=jump[next];
        q.push({next,times+1});
        
      }
    }
    
  }
  
}