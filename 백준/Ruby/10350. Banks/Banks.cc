#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    vector<long long> s(2*N + 1, 0);
    for (int i = 0; i < 2*N; i++) {
        s[i+1] = s[i] + arr[i % N];
    }
    
    long long result = 0;
    long long total_sum = s[N] - s[0];
    
    for (int i = 0; i < N-1; i++) {
        for (int i2 = 1; i2 <= N; i2++) {
            if (s[i2+i] < s[i2-1]) {
                result += ceil(double(s[i2-1] - s[i2+i]) / double(total_sum));
            }
        }
    }

    cout << result;
    return 0;
}