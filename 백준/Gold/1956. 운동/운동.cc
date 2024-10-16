#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int V,E;
  
  
  cin >> V>>E;
  vector<vector<int>>arr(V+1,vector<int>(V+1,0));
  
  int a,b,c;
  for(int i=0;i<E;i++){
    cin >>a>>b>>c;
    arr[a][b]=c;
    
  }
  for(int k=1;k<=V;k++){
  for(int i=1;i<=V;i++){
    for(int j=1;j<=V;j++){
      if(arr[i][k]!=0&&arr[k][j]!=0){
        if(arr[i][j]!=0)
        arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
        else
        arr[i][j]=arr[i][k]+arr[k][j];
      }
      
      
    }
  }}
  
  int min1=1e9;
  for(int i=1;i<=V;i++){
    if(arr[i][i]!=0)
    min1=min(min1,arr[i][i]);
    
  }
  if(min1==1e9)
  cout <<-1;
  else
  cout <<min1;
  
}