#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  vector<int> arr(2000001,0);
  int a;
  for(int i=0;i<N;i++)
  {cin >>a;
  arr[a]++;
  }
  
  long long realsum=0;
  
  for(int i=1;i<=2000000;i++){
  long long sum=0;
    for(int j=1;j*i<=2000000;j++){
      sum+=arr[i*j];
    }
    if(sum<2)continue;
    realsum=max(realsum,sum*i);
  }
  cout << realsum;
}