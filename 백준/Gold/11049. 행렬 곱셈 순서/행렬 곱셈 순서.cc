#include<bits/stdc++.h>
using namespace std;

const long long INF = 2e32;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N + 2);
    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, INF)); 
    long long a, b;

    for (int i = 1; i <= N ; i++) {
            cin >> arr[i] >> arr[i + 1]; 
    }
    
 
    for (int i = 1; i <= N; i++) {
        dp[i][i] = 0;
    }
    for (int L = 2; L <= N; L++) {
        for (int i = 1; i <= N - L + 1; i++) {
            int j = i + L - 1;
            for (int k = i; k < j; k++) {
                long long temp = dp[i][k] + dp[k + 1][j] + (long long)(arr[i] * arr[k + 1] * arr[j + 1]);
                if (temp < dp[i][j]) {
                    dp[i][j] = temp;
                }
            }
        }
    }

    cout << dp[1][N];
    return 0;
}
