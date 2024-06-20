#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    long long sum = 0;
    vector<int>st(10000000, 0);
    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            st[arr[i][j]]++;
            sum += arr[i][j];

        }
    }

    sum = (sum + 1) / 2;

    if (sum == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    long long nowsum = 0;
    nowsum += st[0];
    long long mul = N * N;
    for (int i = 1; i <= 10000000; i++) {
        sum -= mul;
        sum += nowsum;
        nowsum += st[i];
        if (sum<=0)
        {
            cout << i << endl;
            return 0;
        }
    }
}
