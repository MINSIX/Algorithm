#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N,M;
  cin >> N >> M;
  
  vector<vector<int>>arr(N+1);

  int a,b;
  for(int i=0;i<M;i++){
    cin >>a>>b;
    arr[b].push_back(a);

  }
  vector<int> cnt(N+1,0);
  for(int i=1;i<=N;i++){
  vector<bool>visited(N+1);
    queue<int> q;
    q.push(i);
    visited[i]=true;
    while(!q.empty()){
      cnt[i]++;
      
      int now = q.front();

      q.pop();
      for(auto k : arr[now]){
        if(visited[k])
        continue;
        
        visited[k]=true;
        q.push(k);
      }
      
    }
    

  }
  vector<int> mm=cnt;
  sort(mm.begin(),mm.end(),greater<int>());
  int maxi = mm[0];
  for(int i=1;i<=N;i++){
    if(cnt[i]==maxi)
    cout<<i<<" ";
  }
  
  
  
}