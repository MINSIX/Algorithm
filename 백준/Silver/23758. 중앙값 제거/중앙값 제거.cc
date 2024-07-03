#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) 
        cin >> arr[i];
    

    sort(arr.begin(), arr.end());
  
    int result = 0;
    int mid = (N + 1) / 2;
    for (int i = 0; i < mid; i++) {
        int val = arr[i];
        int cnt = 0;
        while (val > 1) {
            cnt++;
            val /= 2;
        }
        result += cnt;
    }
  
    cout << result + 1;
}
