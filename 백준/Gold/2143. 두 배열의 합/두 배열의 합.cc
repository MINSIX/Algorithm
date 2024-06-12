#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    int N, M;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    unordered_map<int, int> sumA_counts;

   for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += A[j];
            sumA_counts[sum]++;
        }
    }

    long long cnt = 0;

    for (int i = 0; i < M; i++) {
        int sum = 0;
        for (int j = i; j < M; j++) {
            sum += B[j];
            cnt += sumA_counts[T - sum];
        }
    }

    cout << cnt << "\n";
    return 0;
}
