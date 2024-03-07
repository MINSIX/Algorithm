#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> item(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> item[i];
    }
    const int INF = 1e9;
    vector<vector<int>> loc(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < r; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        loc[a][b] = l;
        loc[b][a] = l;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = loc[i][j];
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (i != k) {
                for (int j = 1; j <= n; ++j) {
                    if(k!=j&&i!=j)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    vector<int> result(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] <= m) {
                result[i] += item[j];
            }
        }
    }

    int max_result = *max_element(result.begin(), result.end());
    cout << max_result << endl;

    return 0;
}
