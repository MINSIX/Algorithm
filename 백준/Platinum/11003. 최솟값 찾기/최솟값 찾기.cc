#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, L;
    cin >> N >> L;

    deque<pair<long long, int>> dq;
    long long a;
    for (int i = 0; i < N; i++) {
        cin >> a;

        while (!dq.empty() && dq.back().first >= a) {
            dq.pop_back();
        }
        
       dq.push_back({a, i});
        
        if (!dq.empty() && dq.front().second <= i - L) {
            dq.pop_front();
        }
        
       cout << dq.front().first << " ";
    }

    return 0;
}
