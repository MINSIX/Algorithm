#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a;
  cin >> a;
  int sum=2;
  for(int i=1;i<=a;i++){
    sum+=pow(2,i-1);
  }
  cout << sum*sum;
}