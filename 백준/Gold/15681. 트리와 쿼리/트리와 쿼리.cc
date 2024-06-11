#include <bits/stdc++.h>
using namespace std;
int N, R, Q;
vector<bool>visited;
void dpp(vector<vector<int>>&arr,vector<int>& dp,int root) {

    visited[root] = true;
    for (int i : arr[root]) {
        if (visited[i])
            continue;
   
        
      
        if (dp[i] == 1 && arr[i].size() != 1)
        {
            dpp(arr, dp, i);
            dp[root] += dp[i];
        }
        else
            dp[root] += dp[i];

      
     
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> R >> Q;
    vector<vector<int>>arr(N + 1);
    vector<int>dp(N + 1, 1);
    visited.resize(N + 1, false);
    int a, b;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }


    dpp(arr,dp,R);


    for (int i = 0; i < Q; i++) {
        cin >> a;
        cout << dp[a] << "\n";

    }

    return 0;
}
