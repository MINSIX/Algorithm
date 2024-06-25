#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int N, M;
    cin >> N >> M;
    int mini = 1;
    for (int i = 1; i <=min(N,M); i++) {
        if (N % i == 0 && M % i == 0)
            mini = i;

       
    }
    cout << mini << endl;
    cout << N * M / mini << endl;


    return 0;
}
