#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  vector<int> arr(N+1);
  for(int i=1;i<=N;i++)
  cin >>arr[i];
  vector<int> lis;
   vector<int> lis_index(N+1, -1);
    for (int i = 1; i <= N; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end()) {
            lis.push_back(arr[i]);
            lis_index[i] = lis.size() - 1;
        }
        else {
            *it = arr[i];
            lis_index[i] = it - lis.begin();
        }
    }
  
  cout << lis.size();
  
}