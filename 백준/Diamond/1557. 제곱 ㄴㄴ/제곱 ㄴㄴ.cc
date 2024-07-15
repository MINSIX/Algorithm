#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1e6; 

long long memo[MAXN + 1];
bool calculated[MAXN + 1];


long long sqnocnt(long long n) {
  if (n <= MAXN && calculated[n]) return memo[n];
    
    long long result = n;
    for (long long i = 2; i * i <= n; ++i) {
        result -= sqnocnt(n / (i * i));
    }
    if (n <= MAXN) {
        memo[n] = result;
        calculated[n] = true;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    long long left = 1, right = K;
    while (sqnocnt(right) < K) {
        left = right;
        right *= 2;  
    }
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (sqnocnt(mid) < K) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    cout << left;
    return 0;
}