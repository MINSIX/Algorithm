#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> arr(N);
  for(auto &i: arr)
    cin >> i;
  sort(arr.begin(), arr.end());
  int cnt=0, sum=0, cal=0;
  do{
    cal=0;
    for(int i=0;i<N;i++){
      sum=0;
      for(int j=i; j<i+N;j++){
        sum+=arr[j % N];
        if(sum>50)
          break;
        else if(sum==50){
          cal++;
          break;
        }
      }
      cnt = max(cnt, cal);

    }
  }while(next_permutation(arr.begin(), arr.end()));
  cout << cnt/2;
}
