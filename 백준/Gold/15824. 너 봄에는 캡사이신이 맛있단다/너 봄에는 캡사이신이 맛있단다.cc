#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<long long> powerOfTwo(N, 1);
    for (int i = 1; i < N; ++i) {
        powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % MOD;  // 2의 지수 저장
    }

    long long sum = 0;

    for (int i = 0; i < N; ++i) {
        sum = (sum + arr[i] * (powerOfTwo[i] - powerOfTwo[N - i - 1] + MOD)) % MOD;
    }

    cout << sum << endl;

    return 0;
}
