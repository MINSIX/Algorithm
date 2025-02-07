#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

struct tri{
  int x,y;
};
int main(){
  
  int N,M;
  cin >> N >> M;
  vector<vector<int>> arr(N,vector<int>(M));
  for(int i=0;i<N;i++)
  for(int j=0;j<M;j++)
  cin >>arr[i][j];
  
  
  vector<vector<bool>> visited(N,vector<bool>(M,false));
  
  int cnt=0;
  int big=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(visited[i][j]||arr[i][j]==0)
        continue;
      queue<tri> q;
      cnt++;
      q.push({i,j});
      visited[i][j]=true;
      int check=1;
      while(!q.empty()){
      int nowx=q.front().x;
      int nowy=q.front().y;
      q.pop();
      for(int k=0;k<4;k++){
        int xx=dx[k]+nowx;
        int yy=dy[k]+nowy;
        if(xx<0||yy<0||xx>=N||yy>=M)
        continue;
        
        if(arr[xx][yy]==0)
        continue; 
        
        if(visited[xx][yy])
        continue;
        
        visited[xx][yy]=true;
        q.push({xx,yy});
        check++;
        
        
      }
        
      }
      big=max(big,check);
    }
  }
  cout << cnt<<"\n"<<big;
  
  
}