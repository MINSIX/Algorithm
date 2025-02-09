#include<bits/stdc++.h>
using namespace std;

int MOD = 1000000000;


int main(){
  
  long long N, K;
  
  cin >> N >> K;
  
  vector<vector<long long>> arr(K+1,vector<long long>(N+1,0));
  
  arr[0][0]=1;
    for(int i=0; i<=K; i++){
        arr[i][0] = 1;
    }
  for(int i=1;i<=K;i++){
  for(int j=1;j<=N;j++){
    arr[i][j]=(arr[i-1][j]+arr[i][j-1])%MOD;
  }
  }
  


  cout << arr[K][N];
}