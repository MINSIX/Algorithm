#include<bits/stdc++.h>
using namespace std;

long long B(long long N, long long K, long long st, long long ed) {
    while (st < ed) {
        long long mid = (st + ed) / 2;
        long long cnt = 0;

        for (long long i = 1; i <= N; i++) {
            cnt += min(N, mid / i);
        }

        if (cnt < K) {
            st = mid + 1;
        } else {
            ed = mid;
        }
    }
    return st;
}

int main() {
    long long N, K;
    cin >> N >> K;
    cout << B(N, K, 1, N * N);

}
