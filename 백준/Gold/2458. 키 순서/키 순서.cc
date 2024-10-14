#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N,M;
  cin >> N >> M;
  vector<vector<bool>> arr(N+1,vector<bool>(N+1,false));
  int a,b;
  for(int i=0;i<M;i++){
    cin >> a>>b;
    arr[a][b]=true;
  }
  for(int k=1;k<=N;k++){
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++)
{
  if(arr[i][k]&&arr[k][j]){
  arr[i][j]=true;

  }
  
  
  
}  }}
  int cnt=0;
for (int i = 1; i <= N; i++) {
       int nowcnt=0;
        for (int j = 1; j <= N; j++) {
            if (arr[i][j]) {
                nowcnt++; 
            }
            if (arr[j][i]) {
               nowcnt++;
            }
        }

        
        if (nowcnt == N - 1) {
            cnt++;
        }
    }

  cout << cnt;
}