#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, T;
    cin >> N >> T;
    
    vector<pair<int,int>> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    
   vector<int> dp(T+1, 0);
    
    for (int i = 0; i < N; i++){
        for (int t = T; t >= arr[i].first; t--){
            dp[t] = max(dp[t], dp[t - arr[i].first] + arr[i].second);
        }
    }
    
    cout << dp[T];
}
