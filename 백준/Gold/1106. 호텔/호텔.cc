#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;

    vector<pair<int, int>> arr;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        arr.push_back({a, b});
    }

    vector<int> val(C + 1001, INT_MAX);
    val[0] = 0;

    for (int i = 0; i <= C + 1000; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= arr[j].second && val[i - arr[j].second] != INT_MAX) {
                val[i] = min(val[i], val[i - arr[j].second] + arr[j].first);
            }
        }
    }

    int result = INT_MAX;
    for (int i = C; i <= C + 1000; i++) {
        result = min(result, val[i]);
    }
    cout << result;
}
