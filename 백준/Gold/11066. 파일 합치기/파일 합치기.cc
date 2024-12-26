#include<bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    int K;
    cin >> K;
    vector<int> arr(K);
    vector<vector<int>> save(K, vector<int>(K, 0));
    vector<int> prefix_sum(K + 1, 0);
    for(int i = 0; i < K; i++) {
      cin >> arr[i];
      prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }

    for(int len = 2; len <= K; len++) {
      for(int i = 0; i <= K - len; i++) {
        int j = i + len - 1;
        save[i][j] = 1e9;
        for(int k = i; k < j; k++) {
         save[i][j] = min(save[i][j], save[i][k] + save[k + 1][j] + prefix_sum[j + 1] - prefix_sum[i]);
         }
      }
    }

    cout << save[0][K - 1] << "\n";
  }

}
