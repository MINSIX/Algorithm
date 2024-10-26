#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
  vector<bool>visited;

int cnt=0;
int dfs(int now){
  visited[now]=true;
  
  int child[2]={0,0};
  for(int i=0;i<arr[now].size();i++){
    int n=arr[now][i];
    if(!visited[n]){
      child[dfs(n)]++;
    }
  }
  
  if(child[0]){
    cnt++;
    return 1;
  }
  
  return 0;
}

int main(){
  int N;
  cin >> N;
  
  arr.resize(N+1);
  visited.resize(N+1);
  int a,b;
  for(int i=0;i<N-1;i++){
    cin >> a>>b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  
  dfs(1);
  cout << cnt;
  
  
  
}