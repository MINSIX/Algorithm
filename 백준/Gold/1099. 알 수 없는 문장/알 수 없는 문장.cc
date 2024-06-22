#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    int N;
    cin >> s;
    cin >> N;
    vector<string> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> dp(s.length() + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; j < i; j++) {
            string ss = s.substr(j, i - j);
            sort(ss.begin(), ss.end());
            for (int t = 0; t < N; t++) {
                if (arr[t].length() != i - j) continue;

                string nn = arr[t];
                sort(nn.begin(), nn.end());

                if (nn != ss) continue;

                int cnt = 0;
                for (int w = 0; w < nn.size(); w++) {
                    if (s[j + w] != arr[t][w]) cnt++;
                }

                if (dp[j] == -1) continue; 

                if (dp[i] == -1)
                    dp[i] = dp[j] + cnt;
                else
                    dp[i] = min(dp[i], dp[j] + cnt);
            }
        }
    }

    cout << dp[s.length()] << '\n';

    return 0;
}
