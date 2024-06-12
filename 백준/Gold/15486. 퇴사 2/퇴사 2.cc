#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   
    cin >> N;
    
    int t, p;
    vector<pair<int, int>> arr(1500000);
    for (int i = 1; i <= N; i++) {
        cin >> t >> p;
        arr[i].first = t;
        arr[i].second = p;
    }

    vector<int>dp(1500000);
    for (int i = 1; i <= N; i++) {
       
        if (dp[i] < dp[i - 1])
            dp[i] = dp[i - 1];
        dp[i + arr[i].first - 1] = max(dp[i + arr[i].first - 1], dp[i - 1] + arr[i].second);
    }
    cout << dp[N];
}
