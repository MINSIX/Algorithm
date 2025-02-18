#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int T;
  cin >> T;
  
  while(T--){
    int n;
    cin >> n;
    
    vector<vector<long long>>arr(n+1,vector<long long>(4));
    if(n<=3){
    cout << n<<"\n";
    continue;
    }
    arr[1][1]=1;
    arr[2][1]=1;
    arr[2][2]=1;
    arr[3][1]=1;
    arr[3][2]=1;
    arr[3][3]=1;
    for(int i=4;i<=n;i++){
      arr[i][1]=arr[i-1][1];
      arr[i][2]=arr[i-2][1]+arr[i-2][2];
      arr[i][3]=arr[i-3][1]+arr[i-3][2]+arr[i-3][3];
      
    }
    cout <<arr[n][1]+arr[n][2]+arr[n][3]<<"\n";
    
  }
  
  
}