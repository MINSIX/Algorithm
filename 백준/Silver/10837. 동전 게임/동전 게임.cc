#include<bits/stdc++.h>
using namespace std;
int N, M,C,K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> K;
    cin >> C;
    while (C--) {
        
       
            cin >> M >> N;
            int cha = K - max(M, N);
            int diff = abs(M - N);


            if (M > N) {
                if (diff-cha<=2)cout << 1 << '\n';
                else cout << 0 << '\n';
            }
            else if (M < N) {
                if (diff-cha<2)cout << 1 << '\n';
                else cout << 0 << '\n';
            }
            else {
                cout << 1 << '\n';
            }


    }
 
}
