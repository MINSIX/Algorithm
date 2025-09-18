#include<bits/stdc++.h>
using namespace std;




int main(){
  int N;
  cin >> N;
  if(!N)
  {
      cout << 0;
      return 0;
  }
  vector<int> arr(N);
  for(int i=0;i<N;i++){
    cin >>arr[i];
  }
  sort(arr.begin(),arr.end());
  int cut=round((double)N*0.15);
  int sum=0;
  for(int i=cut;i<N-cut;i++){
    sum+=arr[i];
  }
  cout << round((double)sum/(N-2*cut));
}