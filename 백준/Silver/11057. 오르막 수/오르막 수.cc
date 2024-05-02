#include<bits/stdc++.h>
using namespace std;
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<vector<int>>arr(1001, vector<int>(10, 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 9; j >= 0; j--) {
            for (int k = j; k < 9; k++) {
                arr[i][j] += arr[i - 1][k]%10007;

            }



        }
    }
    cout << arr[N][0] % 10007 << endl;

  
    
}
