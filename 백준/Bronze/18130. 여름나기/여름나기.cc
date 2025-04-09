#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    long long ansIndex = 0;
    long long ansCost  = LLONG_MAX;

    for(int i = 1; i <= N; i++){
        long long P, K, C; 
        cin >> P >> K >> C;

        long long T = (Q - 1) / K; 

        long long addCost = C * T * (T + 1) / 2;

        long long totalCost = P + addCost;

        if(totalCost < ansCost) {
            ansCost  = totalCost;
            ansIndex = i;
        }
    }

    cout << ansIndex << " " << ansCost ;
}
