#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N,M;
  cin >> N >> M;
  vector<vector<char>>arrA(N,vector<char>(M));
  
  vector<vector<char>>arrB(N,vector<char>(M));
  
  for(int i=0;i<N;i++)
  {for(int j=0;j<M;j++){
    cin >>arrA[i][j];
  }}
  
  for(int i=0;i<N;i++)
  {for(int j=0;j<M;j++){
    cin >>arrB[i][j];
  }}
  int cnt=0;
  for(int i=0;i<N-2;i++)
  {for(int j=0;j<M-2;j++){
   if(arrA[i][j]!=arrB[i][j])
   {
     for(int k=i;k<=i+2;k++){
     for(int l=j;l<=j+2;l++){
       arrA[k][l]=(arrA[k][l]=='1')?'0':'1';
       
     }  
     }
     
   cnt++;
   }else
   continue;
    
  }
  }
  
  for(int i=0;i<N;i++)
  {for(int j=0;j<M;j++){
    if(arrA[i][j]!=arrB[i][j])
    {cout << -1;
      return 0;
    }
    
  }}
  cout <<cnt;
}