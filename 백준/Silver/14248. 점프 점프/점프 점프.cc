#include<bits/stdc++.h>
using namespace std;


int main(){
 int N;
 cin >> N;
  vector<int>arr(N+1);
  for(int i=1;i<=N;i++)
  cin >> arr[i];
  int start;
  cin >>start;
  
  vector<bool>visited(N+1,false);
  queue<int> q;
  q.push(start);
  visited[start]=true;
  while(!q.empty()){
    int nowposition =q.front();
    int canjump=arr[q.front()];

    q.pop();
    
    int jumpleft=nowposition-canjump;
    int jumpright=nowposition+canjump;
    
    if(jumpleft<1||jumpleft>N)
    ;
    else if(visited[jumpleft])
    ;
    else{
      q.push(jumpleft);
      visited[jumpleft]=true;
    }
    if(jumpright<1||jumpright>N)
    ;
    else if(visited[jumpright])
    ;    
    else{
      q.push(jumpright);
      visited[jumpright]=true;
    }
    
    
    
  }
  int cnt=0;
  for(int i=1;i<=N;i++)
  if(visited[i])
  cnt++;
  cout << cnt;
  
}