#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1000000009;
int T;
vector<long long> dp(100001,0);
void cal(int n) {

    for (int i = 7; i <= n; i++)
    {

     
        dp[i] = (dp[i - 4] + dp[i - 2]+dp[i-6]) % MOD;

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    int n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 3;
    dp[6] = 6;

    cal(100000);
    while (T-- > 0) {
        cin >> n;
        
        cout << dp[n]  << endl;


    }



    return 0;
}
