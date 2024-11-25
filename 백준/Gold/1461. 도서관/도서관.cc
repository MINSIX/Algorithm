#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int cnt = 0;

    vector<int> positive, negative;
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) positive.push_back(arr[i]);
        else negative.push_back(abs(arr[i]));
    }

    sort(positive.rbegin(), positive.rend());
    sort(negative.rbegin(), negative.rend());

    if (!positive.empty() && (negative.empty() || positive[0] >= negative[0])) {
        cnt += positive[0];
        for (int i = 0; i < M && i < positive.size(); i++)
            positive[i] = 0;
    } else if (!negative.empty()) {
        cnt += negative[0];
        for (int i = 0; i < M && i < negative.size(); i++)
            negative[i] = 0;
    }

    for (int i = 0; i < positive.size(); i += M) {
        if (positive[i] > 0)
            cnt += 2 * positive[i];
    }

    for (int i = 0; i < negative.size(); i += M) {
        if (negative[i] > 0)
            cnt += 2 * negative[i];
    }

    cout << cnt;
}
