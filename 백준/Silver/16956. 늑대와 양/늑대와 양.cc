#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

int main(){
  
  int R,C;
  cin >> R>>C;
  
  vector<vector<char>>arr(R,vector<char>(C));
  for(int i=0;i<R;i++)
  for(int j=0;j<C;j++)
  cin >>arr[i][j];
  
  int cal=1;
  
  
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(arr[i][j]=='.')
      arr[i][j]='D';
      
      if(arr[i][j]=='S'){
        for(int t=0;t<4;t++){
          int xx=i+dx[t];
          int yy=j+dy[t];
          
          if(xx<0||yy<0||xx>=R||yy>=C)
          continue;
          
          if(arr[xx][yy]=='W')
          {
            cal =0;
            break;
            
          }
        }
      }
      
      
    }
  }
  if(!cal)
  cout << 0;
  else
  {
    cout << 1<<"\n";
    for(int i=0;i<R;i++)
    {for(int j=0;j<C;j++)
    { cout << arr[i][j];
    }cout<<"\n";
  }}
  
}