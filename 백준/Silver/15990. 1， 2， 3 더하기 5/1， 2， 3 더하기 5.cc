#include<bits/stdc++.h>
using namespace std;



int MOD=1000000009;


vector<vector<long long>>arr(100001,vector<long long>(4,0));

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
    arr[1][1]=1;
    arr[2][2]=1;
    arr[3][1]=1;
    arr[3][2]=1;
    arr[3][3]=1;
    
    for(int i=4;i<=100000;i++){
      arr[i][1]=(arr[i-1][2]+arr[i-1][3])%MOD;
      arr[i][2]=(arr[i-2][1]+arr[i-2][3])%MOD;
      arr[i][3]=(arr[i-3][2]+arr[i-3][1])%MOD;
      
      
    }
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    if(N<3)
    cout << 1<<"\n";
    else
    cout << (arr[N][1]+arr[N][2]+arr[N][3])%MOD<<"\n";
    
  }
  
  
  
}