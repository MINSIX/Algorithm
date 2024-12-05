#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    if (N % 2 == 1) {
        cout << 0;
        return 0;
    }

    vector<long long> arr(N + 1, 0);
    arr[0] = 1; 
    arr[2] = 3; 

    for (int i = 4; i <= N; i += 2) {

        arr[i] = (arr[i - 2] * 3) % MOD;

        for (int j = 4; j <= i; j += 2) {
            arr[i] = (arr[i] + (2 * arr[i - j]) % MOD) % MOD;
        }
    }

    cout << arr[N];
}
