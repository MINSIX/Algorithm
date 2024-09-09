#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<long long> arr(N); // Use long long for arr to avoid overflow

    long long cnt = 0; // Use long long for cnt
    vector<int> ss(M, 0); // ss should have size M and initialize to 0
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (i > 0) {
            arr[i] += arr[i - 1];
        }
        long long S = arr[i] % M;
        if (S < 0) S += M; // Handle negative modulo results
        if (S == 0) cnt++;
        cnt += ss[S];
        ss[S]++;
    }

    cout << cnt;

    return 0;
}
