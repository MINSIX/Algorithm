#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<int> check(M);
    for (int i = 0; i < M; i++){
        cin >> check[i];
    }
    sort(check.begin(), check.end());
    
   
   vector<long long> dp(N+2, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    long long ans = 1;
    int pre = 1;
    
    for (int i = 0; i < M; i++){
        int gap = check[i] - pre; 
        ans *= dp[gap];
        pre = check[i] + 1;
    }
    
    int gap = (N + 1) - pre;
    ans *= dp[gap];
    
    cout << ans;
}
