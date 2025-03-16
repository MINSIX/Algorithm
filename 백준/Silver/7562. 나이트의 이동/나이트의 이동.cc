#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

struct tri{
  int x,y,val;
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int  T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vector<vector<bool>>visited(N,vector<bool>(N,false));
    queue<tri> q;
    int st,ed;
    int cnt=0;
    cin >>st>>ed;
    int goalx,goaly;
    cin >>goalx>>goaly;
    q.push({st,ed,0});
    visited[st][ed]=true;
    int flag=false;
    while(!q.empty()){
      int nowx=q.front().x;
      int nowy=q.front().y;
      int val=q.front().val;
      q.pop();
      for(int i=0;i<8;i++){
        int xx=nowx+dx[i];
        int yy=nowy+dy[i];
        if(xx<0||yy<0||xx>=N||yy>=N)
        continue;
        
        if(visited[xx][yy])
        continue;
        
        if(xx==goalx&&yy==goaly)
        {
          flag=true;
          cnt=val+1;
          break;
        }
        
        visited[xx][yy]=true;
        q.push({xx,yy,val+1});
        
        
      }
      if(flag)
      break;
      
    }
    cout << cnt<<"\n";
    
  }
  
}