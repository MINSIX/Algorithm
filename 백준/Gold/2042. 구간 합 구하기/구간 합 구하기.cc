#include<bits/stdc++.h>

using namespace std;
vector<long long> segment_tree;
long long t, M,K;
void create(long long start, long long end, long long index, long long check, vector<long long>& source_list) {
    long long _check = check;
    if (start >= end && _check == 1) // 말단 노드를 초과했는지 검사
        return;

    long long temp_sum = 0;
    for (long long i = start; i <= end; ++i) // start부터 end까지의 합을 트리에 추가
        temp_sum += source_list[i];
    segment_tree[index] = temp_sum;

    if (start >= end && _check == 0) // 말단 노드인지 구분
        _check = 1;

    long long middle = (start + end) / 2;
    create(start, middle, index * 2, _check, source_list);
    create(middle + 1, end, index * 2 + 1, _check, source_list);
}

long long sum(long long root_index, long long start, long long end, long long left, long long right) {
    if (start >= left && end <= right) // 완전히 겹칠 때
        return segment_tree[root_index];
    if (end < left || right < start) // 겹치는 부분 없을 때
        return 0;

    long long middle = (start + end) / 2;
    long long left_result = sum(root_index * 2, start, middle, left, right);
    long long right_result = sum(root_index * 2 + 1, middle + 1, end, left, right);
    return left_result + right_result;
}

long long search(long long change_index, long long start, long long end, long long root_index = 1) {
    while (start != end) {
        long long middle = (start + end) / 2;
        if (change_index <= middle) {
            end = middle;
            root_index *= 2;
        }
        else if (change_index > middle) {
            start = middle + 1;
            root_index = root_index * 2 + 1;
        }
    }
    return root_index;
}

void update(long long update_index, long long update_value, long long n, long long root_index = 1) {
    long long tree_array_index = search(update_index, 0, n - 1); 
    long long preValue = segment_tree[tree_array_index]; 
    long long gap = update_value - preValue;
    segment_tree[tree_array_index] = update_value;
    tree_array_index /= 2;
    while (tree_array_index > 0) {
        segment_tree[tree_array_index] += gap;
        tree_array_index /= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> M>>K;
    vector<long long> source_list(t);
    for (long long i = 0; i < t; i++)
        cin >> source_list[i];

    long long n = source_list.size();
    long long size = pow(2, ceil(log2(n)) + 1) - 1; // 필요한 노드의 수 계산
    segment_tree.resize(size + 1);
    long long index = 1, check = 0;
    create(0, source_list.size() - 1, index, check, source_list);
    long long a, b, c;
    for (long long i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;

        if (a == 1) {
            //update b to c

            update(b - 1, c, n);

        }
        else if (a == 2) {
            //prlong long sum b to c
            cout << sum(1, 1,n, b, c)<<endl;

        }
    }

}