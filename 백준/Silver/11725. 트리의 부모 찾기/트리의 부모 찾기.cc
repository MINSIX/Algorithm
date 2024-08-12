#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int N;
  cin >> N;
  vector<vector<int>>edge(N+1);
  vector<bool>visited(N+1,false);
  vector<int>par(N+1);
  int a,b;
  for(int i=1;i<=N;i++){
    cin >>a>>b;
    if(a==1){
      edge[a].push_back(b);
      continue;
      
      
    }
    if(b==1){
      edge[b].push_back(a);
    continue;
      
    }
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  stack<int>st;
  st.push(1);
  visited[1]=true;
  while(!st.empty()){
    int now = st.top();
    st.pop();
    for(auto k : edge[now]){
      if(visited[k])
      continue;
      
      par[k]=now;
      visited[k]=true;
      st.push(k);
    }
    
  }
  for(int i=2;i<=N;i++)
    cout << par[i]<<"\n";
}