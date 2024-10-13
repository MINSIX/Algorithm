#include<bits/stdc++.h>
using namespace std;

int dy[6]={-1,0,0,1,0,0};
int dz[6]={0,-1,1,0,0,0};
int dx[6]={0,0,0,0,-1,1};


int main(){
  
  int a,b,c;
  while(cin >> a>>b>>c){
  if(a==0&&b==0&&c==0)
  break;
    
    vector<vector<vector<char>>> arr(a,vector<vector<char>>(b,vector<char>(c)));
  queue<pair<pair<int,int>,pair<int,int>>>q;
  vector<vector<vector<bool>>>visited(a,vector<vector<bool>>(b,vector<bool>(c)));
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      for(int k=0;k<c;k++){
        cin >>arr[i][j][k];
        if(arr[i][j][k]=='S')
     {   q.push({{i,j},{k,0}});
        visited[i][j][k]=true;
       
     }}
    }
  }    
  bool isExit=false;
   while(!q.empty()){
     int nowx=q.front().first.first;
     int nowy=q.front().first.second;
     int nowz=q.front().second.first;
     int val=q.front().second.second;
     q.pop();
     
     for(int i=0;i<6;i++){
       int xx=nowx+dx[i];
       int yy=nowy+dy[i];
       int zz=nowz+dz[i];
       
      if(xx<0||yy<0||zz<0||xx>=a||yy>=b||zz>=c)
      continue;
      
      if(visited[xx][yy][zz])
      continue;
      
      if(arr[xx][yy][zz]=='#')
      continue;
      
      if(arr[xx][yy][zz]=='E')
      {
        cout << "Escaped in " <<val+1<< " minute(s).\n";
        isExit=true;
        break;
      }
       
     q.push({{xx,yy},{zz,val+1}});  
       visited[xx][yy][zz]=true;
     }
     if(isExit)
     break;
     
     
     
   } 
   if(!isExit)
    cout << "Trapped!\n";
    
    
  }
  
  
  
}