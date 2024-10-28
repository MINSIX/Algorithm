#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  
  int N;
  cin >> N;
  
  map<int,int> mm;
  int a;
  for(int i=0;i<N;i++){
    cin >>a;
    mm[a]++;
  }
  
  
  int M;
  cin >> M;
  for(int i=0;i<M;i++){
    cin >> a;
    cout << mm[a]<<" ";
  }
  
  
  
}