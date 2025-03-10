#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N>>M;
  
  vector<vector<int>>arr(N+1,vector<int>(N+1,1e9));
  vector<vector<int>>mm(N+1,vector<int>(N+1,0));
  
  int a,b,c;
  
  for(int i=0;i<M;i++)
  {
    cin >>a>>b>>c;
    arr[a][b]=c;
    arr[b][a]=c;
    mm[a][b]=b;
    mm[b][a]=a;
  }
  for(int k=1;k<=N;k++){
  for(int i=1;i<=N;i++){
  if(k==i)
  continue;
    for(int j=1;j<=N;j++){
      if(k==j||i==j)
      continue;
      if(arr[i][k]==1e9 || arr[k][j]==1e9) continue;
        if(arr[i][j] > arr[i][k] + arr[k][j]){
          arr[i][j] = arr[i][k] + arr[k][j];
          mm[i][j] = mm[i][k];
        }
      
      
    }
  }
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(mm[i][j]==0)
      cout<<"- ";
      else
      cout << mm[i][j]<<" ";
    }
    cout<<endl;
  }
  
  
}