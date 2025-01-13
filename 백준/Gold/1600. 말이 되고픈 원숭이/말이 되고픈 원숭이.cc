#include<bits/stdc++.h>
using namespace std;

struct tri{
  int x,y,horsecnt,cnt;
  
};

int dx[12]={-1,0,0,1,-2,-2,-1,-1,1,1,2,2};
int dy[12]={0,-1,1,0,-1,1,-2,2,-2,2,-1,1};



int main(){
  int K;
  cin >> K;
  int W,H;
  cin >> H>>W;
  int arr[201][201];
  for(int i=0;i<W;i++){
    for(int j=0;j<H;j++){
    
      cin >>arr[i][j];
  }}
  if(W==1&&H==1)
  {cout << 0;
  return 0;}
  queue<tri> q;
  
  static bool visited[201][201][31];
  
  memset(visited, false, sizeof(visited));
  q.push({0,0,0,0});
  visited[0][0][0]=true;
  
  while(!q.empty()){
    int nowx=q.front().x;
    int nowy=q.front().y;
    int canhorse=q.front().horsecnt;
    int cnt=q.front().cnt;
    
    q.pop();
    
     
    for(int i=0;i<12;i++)
    {
      int xx=nowx+dx[i];
      int yy=nowy+dy[i];
      
      int nowhorse = canhorse;
      if(i>=4)
      nowhorse+=1;
      
      if(xx<0||yy<0||xx>=W||yy>=H)
      continue;
      
      if(arr[xx][yy])
      continue;
      
      if(nowhorse>K)
      continue;
       if(xx==W-1&&yy==H-1)
      {
        cout << cnt+1;
        return 0;
      }
      if(!visited[xx][yy][nowhorse])
     { visited[xx][yy][nowhorse]=true;
      q.push({xx,yy,nowhorse,cnt+1});
     }
    }
    }
  cout << -1;
  
  
  
}