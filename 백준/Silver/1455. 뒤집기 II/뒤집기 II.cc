#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N,M;
  cin >> N >> M;
  vector<vector<char>>arr(N,vector<char>(M));
  
  for(int i=0;i<N;i++)
  for(int j=0;j<M;j++)
  cin >>arr[i][j];
  
  int cnt=0;
  
  for(int i=N-1;i>=0;i--){
    for(int j=M-1;j>=0;j--){
      if(arr[i][j]!='0'){
        for(int k=i;k>=0;k--){
          for(int l=j;l>=0;l--){
            arr[k][l]=(arr[k][l]=='0')?'1':'0';
          }
        }
        cnt++;
      }
      
    }
  }
  for(int i=0;i<N;i++)
  {for(int j=0;j<M;j++){
    if(arr[i][j]=='1'){
      cout << -1;
      return 0;
    }
    
  }}
  cout << cnt;
  
}