#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M,K;
  cin >> N >> M >> K;
  
  vector<vector<int>> arr(N,vector<int>(M));
  for(int i=0;i<N;i++)
  for(int j=0;j<M;j++)
  cin >>arr[i][j];
  
  vector<int>sum(N,0);
  
  for(int j=0;j<M;j++){
  for(int i=0;i<N;i++){
    sum[i]+=arr[i][j];
      if(sum[i]>=K){
        cout << i+1<<" "<<j+1;
        return 0;
      }
    }
  }
  
  
}