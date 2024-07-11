#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    int N;
    cin >> N;
    vector<int> arr(N+1, 0);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
  
    long long cnt = 0;
    for (int i = 1; i <= N-2; i++) {
        long long mini;
        if (arr[i+1] <= arr[i+2]) {
            mini = min({arr[i], arr[i+1], arr[i+2]});
            cnt += 7LL * mini;
            arr[i] -= mini;
            arr[i+1] -= mini;
            arr[i+2] -= mini;
          
            mini = min(arr[i], arr[i+1]);
            cnt += 5LL * mini;
            arr[i] -= mini;
            arr[i+1] -= mini;
          
            cnt += 3LL * arr[i];
        } else {
            mini = min(arr[i+1] - arr[i+2], arr[i]);
            cnt += 5LL * mini;
            arr[i] -= mini;
            arr[i+1] -= mini;
          
            mini = min({arr[i], arr[i+1], arr[i+2]});
            cnt += 7LL * mini;
            arr[i] -= mini;
            arr[i+1] -= mini;
            arr[i+2] -= mini;
          
            cnt += 3LL * arr[i];
        }
    }
  

    long long mini = min(arr[N-1], arr[N]);
    cnt += 5LL * mini;
    arr[N-1] -= mini;
    arr[N] -= mini;
    cnt += 3LL * arr[N-1] + 3LL * arr[N];
  
    cout << cnt << "\n";
    return 0;
}