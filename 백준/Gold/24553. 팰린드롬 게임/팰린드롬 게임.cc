#include <bits/stdc++.h>
using namespace std;
int T;
long long N;

const int INF = 1e6+1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while(T--){
    cin >> N;
    N %= 10;
    if (N == 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    
    }return 0;
    
}