#include <bits/stdc++.h>
using namespace std;

vector<long long> arr, prefixSum;
int N, Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> Q;
    arr.resize(N);
    prefixSum.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    prefixSum[0] = arr[0];
    for (int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    
    for(int i=0;i<Q;i++) {
        long long a;
        cin >> a;

        int idx = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
        long long leftCount = idx;
        long long rightCount = N-idx;
        
        long long leftSum=0;
        if(leftCount>0)
        leftSum=prefixSum[leftCount-1];
        else
        leftSum=0;
        
        long long rightSum = prefixSum[N-1]-leftSum;

        long long result = (a * leftCount - leftSum) + (rightSum - a * rightCount);
        cout << result << "\n";
    }

}
