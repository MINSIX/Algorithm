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

    long long sum = 0;
    vector<long long> powerOfTwo(N, 1);

    for (int i = 1; i < N; ++i) {
        powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % MOD;  //2의 지수저장
    }

    for (int st = 0; st < N; st++) {
        for (int ed = st + 1; ed < N; ed++) {
            long long cal = (arr[ed] - arr[st]) % MOD;
            long long cal2 = (cal * powerOfTwo[ed - st - 1]) % MOD;
            sum = (sum + cal2) % MOD;
        }
    }

    cout << sum << endl;

    return 0;
}
