#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<vector<long long>> sum(N, vector<long long>(2));
    sum[0][0] = 0; sum[0][1] = arr[0];
    for (int i = 1; i < N; i++) {
        sum[i][0] = sum[i - 1][1];
        sum[i][1] = min(sum[i - 1][0] + arr[i], sum[i - 1][1] + arr[i]);


    }
    cout << min(sum[N - 1][0], sum[N - 1][1]);
   

    return 0;
}
