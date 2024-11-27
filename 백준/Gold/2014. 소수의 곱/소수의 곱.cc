#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    vector<long long> arr(K);
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    map<long long,int> mm;
    long long mv=0;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
        mv=max(mv,arr[i]);
        mm[arr[i]]++;
    }

    long long result = 0;
    for (int cnt = 0; cnt < N; cnt++) {
        result = pq.top();
        pq.pop();

        for (int i = 0; i < K; i++) {
            long long next = result * arr[i];
            if (pq.size() >= N && next >= mv)
				      continue;
            if (mm[next]==0) {
                pq.push(next);
                mm[next]++;
                mv=max(next,mv);
            }
        }
    }

    cout << result;
}
