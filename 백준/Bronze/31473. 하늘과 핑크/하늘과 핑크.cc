#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int N;
  cin >>N;
  int asum=0;
  int a,b;
  int bsum=0;
  for(int i=0;i<N;i++){
    cin >>a;
    asum+=a;
  }
  
  for(int i=0;i<N;i++){
    cin >>a;
    bsum+=a;
  }
  
  cout << bsum<<" "<<asum;
  
  
}