#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  
  //제거하여 인벤토리에 넣기 2초
  //꺼내어 놓기 1초
  int N,M,B;
  cin >> N >> M >> B;
  int resulthigh=999999999,resulttime=999999999;
  vector<vector<int>>height(N,vector<int>(M));
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >>height[i][j];
    }
  }
  
  for(int k=0;k<=256;k++){
  int add=0;
  int minus=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      
      if(height[i][j]>k){
        minus+=height[i][j]-k;
      }else if(height[i][j]<k){
        add+=k-height[i][j];
      }
    }
  }
  if(B+minus>=add){
    int time=minus*2+add;
    if(time<=resulttime){
      resulttime=time;
      resulthigh=k;
    }
  }
    
  }
  
 cout << resulttime<<" "<<resulthigh; 
}