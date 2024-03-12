#include<bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int len = s.length();

    // 팰린드롬 여부를 저장하는 배열
    vector<vector<bool>> isPalindrome(len, vector<bool>(len, false));

    // 팰린드롬 여부 계산
    for (int i = 0; i < len; i++) {
        isPalindrome[i][i] = true; // 길이가 1인 경우
    }
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            isPalindrome[i][i + 1] = true; // 길이가 2인 경우
        }
    }
    for (int k = 3; k <= len; k++) {
        for (int i = 0; i <= len - k; i++) {
            int j = i + k - 1;
            if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                isPalindrome[i][j] = true;
            }
        }
    }

    // 최소 분할 수 계산
    vector<int> dp(len + 1, INF);
    dp[0] = 0; // 빈 문자열은 0번 분할

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            if (isPalindrome[j][i - 1]) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    cout << dp[len]  << endl; // 마지막에 추가된 1을 빼고 출력

    return 0;
}
