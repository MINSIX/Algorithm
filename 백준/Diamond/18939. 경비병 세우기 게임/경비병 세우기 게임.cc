#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while(T--){
    int N,M,K;
    cin >> N >> M >> K;
    if(max(N,M)<K*2)
    {cout << "Yuto"<<"\n";
      continue;
      
    }
    if(N*M%2==1){
      cout << "Yuto"<<"\n";
      continue;
      
    }
      cout << "Platina"<<"\n";
    
    
  }
  
  
  
}