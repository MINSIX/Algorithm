#include<bits/stdc++.h>
using namespace std;

vector<long long> source_list;
vector<pair<long long, long long>> segment_tree;

void build_tree(long long start, long long end, long long index) {
    if (start == end) {
        segment_tree[index] = {source_list[start], source_list[start]};
        return;
    }

    long long middle = (start + end) / 2;
    build_tree(start, middle, 2 * index);
    build_tree(middle + 1, end, 2 * index + 1);

    segment_tree[index].first = min(segment_tree[2 * index].first, segment_tree[2 * index + 1].first);
    segment_tree[index].second = max(segment_tree[2 * index].second, segment_tree[2 * index + 1].second);
}

pair<long long, long long> query(long long start, long long end, long long left, long long right, long long index) {
    if (left > end || right < start) // 구간이 아예 겹치지 않음
        return {LLONG_MAX, LLONG_MIN};
    if (left <= start && right >= end) // 구간이 완전히 포함됨
        return segment_tree[index];

    long long middle = (start + end) / 2;
    pair<long long, long long> left_result = query(start, middle, left, right, 2 * index);
    pair<long long, long long> right_result = query(middle + 1, end, left, right, 2 * index + 1);

    return {min(left_result.first, right_result.first), max(left_result.second, right_result.second)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t, M;
    cin >> t >> M;

    source_list.resize(t);
    for (long long i = 0; i < t; i++)
        cin >> source_list[i];

    long long n = source_list.size();
    segment_tree.resize(4 * n);
    build_tree(0, n - 1, 1);

    long long a, b;
    for (long long i = 0; i < M; i++) {
        cin >> a >> b;
        pair<long long, long long> result = query(0, n - 1, a - 1, b - 1, 1);
        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}
