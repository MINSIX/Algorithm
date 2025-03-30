#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int a,sum=0;
  for(int i=0;i<N;i++){
    cin >> a;
    sum+=a;
  }
  cout << sum;
}