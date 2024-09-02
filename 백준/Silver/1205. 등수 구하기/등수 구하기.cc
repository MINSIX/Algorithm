#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,New,P;
  cin >> N >> New >> P;
  
  vector<int>arr(P);
  
  for(int i=0;i<N;i++)
  cin >>arr[i];
  
  int t = upper_bound(arr.begin(),arr.begin()+N,New,greater<int>())-arr.begin();
  if(t==P)
  cout << -1;
  else{
  if (t > 0 && arr[t - 1] == New) {
            while (t > 0 && arr[t - 1] == New) {
            t--;
    }
  }
    
    cout << t+1;
    
  }
  
  
}