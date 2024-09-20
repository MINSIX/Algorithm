#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int N, M;
vector<vector<int>> arr;
vector<vector<int>> dp;

int dfs(int x, int y) {

    if (x == N - 1 && y == M - 1) {
        return 1;
    }

    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    dp[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx < 0 || yy < 0 || xx >= N || yy >= M || arr[xx][yy] >= arr[x][y]) {
            continue;
        }

        dp[x][y] += dfs(xx, yy);
    }

    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    arr.resize(N, vector<int>(M));
    dp.resize(N, vector<int>(M, -1));  

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int result = dfs(0, 0); 
    cout << result << "\n"; 

    return 0;
}
