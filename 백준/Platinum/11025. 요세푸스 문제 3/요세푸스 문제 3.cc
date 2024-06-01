#include<bits/stdc++.h>
using namespace std;

int josephus(int n, int k) {
    int result = 0; 
    for (int i = 1; i <= n; ++i) {
        result = (result + k) % i;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    cout << josephus(N, K) + 1 << endl;

    return 0;
}
