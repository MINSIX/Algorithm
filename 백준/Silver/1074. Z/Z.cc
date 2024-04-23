#include<bits/stdc++.h>
using namespace std;

long long Z(long long N, long long r, long long c) {
    if (N == 0) return 0;
    
    
    long long line = pow(2, N);
    long long total = pow(line, 2);
    
    if (r < line / 2) {
        if (c < line / 2)
            return Z(N - 1, r, c);
        else return Z(N - 1, r, c - line / 2) + total / 4;
    }
    else {
        if (c < line / 2)
            return Z(N - 1, r - line / 2, c) + total / 2;
        else return Z(N - 1, r - line / 2, c - line / 2) + 3 * total / 4;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, r, c;
    cin >> N >> r >> c;
    cout << Z(N, r, c) << endl;
    return 0;
}