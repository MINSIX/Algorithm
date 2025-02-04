#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};


struct tri{
  int x,y,val;
};

int main(){
  
  int N,M;
  cin >> N >> M;
  vector<vector<char>> arr(N,vector<char>(M));
  
  for(int i=0;i<N;i++)
  for(int j=0;j<M;j++)
  cin >>arr[i][j];
  
  
  
  queue<tri> q;
  int cnt=0;
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++){
        if(arr[i][j]=='W')
          continue;
      vector<vector<bool>> visited(N, vector<bool>(M, false));
      visited[i][j] = true;
      int nowcnt=0;
      q.push({i,j,0});
      
      
      while(!q.empty()){
        int nowx=q.front().x;
        int nowy=q.front().y;
        int cur=q.front().val;
        q.pop();
        nowcnt=cur;
        for(int k=0;k<4;k++)
        {
          int xx=nowx+dx[k];
          int yy=nowy+dy[k];
          
          if(xx<0||yy<0||xx>=N||yy>=M)
          continue;
          if(visited[xx][yy])
          continue;
          if(arr[xx][yy]=='W')
          continue;
          
          q.push({xx,yy,cur+1});
          visited[xx][yy]=true;
          
          
        }
        
        
      }
      cnt=max(nowcnt,cnt);
      
    }
  }
  
  cout <<cnt;
  
}