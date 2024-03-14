#include<bits/stdc++.h>

using namespace std;
const int INF = 1e9;
int A;
int arr[1000001] = { 0, };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A;
    for (int i = 1; i <= A; i++)
        cin >> arr[i];

    vector<int>dp(A + 1, 1);
    for (int i = 2; i <= A; i++) {
        for (int j = 1; j < i; j++) {

            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }

        }
    }
    int result = *max_element(dp.begin(), dp.end());
    vector<int> lis;
    for (int i = A; i > 0; i--) {
        if (dp[i] == result) {
            lis.push_back(arr[i]);
            result --;
        }
    }
    cout << lis.size() << endl;
    for (int i = lis.size() - 1; i >= 0; --i) {
        cout << lis[i] << " ";
    }
    cout << endl;
}