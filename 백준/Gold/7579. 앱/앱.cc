#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

int N, M;
int dp[101][10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;


    vector<int> mm(N + 1, 0);
    vector<int> cm(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> mm[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> cm[i];
    }
    int sum = INF;
    if (N == 1) {
        cout << cm[0];
        return 0;
    }
     dp[0][cm[0]] = mm[0];
 
     for (int i = 1; i < N; i++) {
         for (int j = 0; j <= 10000; j++) {
             if (j - cm[i] >= 0) {
                 dp[i][j] = max(dp[i][j], dp[i - 1][j - cm[i]] + mm[i]); // 수정된 부분
             }
            
                 dp[i][j] = max(dp[i][j], dp[i - 1][j]);
          

             if (dp[i][j] >= M)
                 sum = min(sum, j);
         }
     }



     cout << sum << endl;
    

}