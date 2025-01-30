#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

struct tri{
  int redx,redy,bluex,bluey,cnt;
};

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<char>> arr(N, vector<char>(M));
  pair<int,int> red;
  pair<int,int> blue;
  pair<int,int> hole;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> arr[i][j];
      if(arr[i][j]=='R'){
        red.first=i;
        red.second=j;
      }
      if(arr[i][j]=='B'){
        blue.first=i;
        blue.second=j;
      }
      if(arr[i][j]=='O'){
        hole.first=i;
        hole.second=j;
      }
    }
  }
  queue<tri> q;
  vector<vector<vector<vector<bool>>>> visited(N, vector<vector<vector<bool>>>(M, vector<vector<bool>>(N, vector<bool>(M,false))));
  q.push({red.first, red.second, blue.first, blue.second, 0});
  visited[red.first][red.second][blue.first][blue.second] = true;

  while(!q.empty()){
    int nowx = q.front().redx;
    int nowy = q.front().redy;
    int bluenowx = q.front().bluex;
    int bluenowy = q.front().bluey;
    int nowval = q.front().cnt;
    q.pop();

    if(nowval >=10) break;

    for(int i=0;i<4;i++){
      int xx = nowx;
      int yy = nowy;
      int bluexx = bluenowx;
      int blueyy = bluenowy;
      int rc=0;
      while(arr[xx+dx[i]][yy+dy[i]]!='#' && arr[xx][yy]!='O'){
        xx += dx[i];
        yy += dy[i];
        rc++;
      }
      int bc=0;
      while(arr[bluexx+dx[i]][blueyy+dy[i]]!='#' && arr[bluexx][blueyy]!='O'){
        bluexx += dx[i];
        blueyy += dy[i];
        bc++;
      }
      if(arr[bluexx][blueyy]=='O') continue;
      if(arr[xx][yy]=='O'){
        cout << nowval + 1;
        return 0;
      }
      if(xx == bluexx && yy == blueyy){
        if(arr[xx][yy] != 'O'){
          if(rc > bc){
            xx -= dx[i];
            yy -= dy[i];
          } else {
            bluexx -= dx[i];
            blueyy -= dy[i];
          }
        }
      }
      if(!visited[xx][yy][bluexx][blueyy]){
        visited[xx][yy][bluexx][blueyy] = true;
        q.push({xx, yy, bluexx, blueyy, nowval+1});
      }
    }
  }
  cout << -1;
}
