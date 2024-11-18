#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
    return x.second < y.second;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> intervals;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        intervals.push_back({a, b});
    }

    sort(intervals.begin(), intervals.end(),cmp);

    int d;
    cin >> d;

    multiset<int> active; 
    int max_count = 0;

    for (auto k : intervals) {

        while (!active.empty() && *active.begin() < k.second - d)
            active.erase(active.begin());

        if (k.second - k.first <= d) 
            active.insert(k.first);

        max_count = max(max_count, (int)active.size());
    }

    cout << max_count;
}
