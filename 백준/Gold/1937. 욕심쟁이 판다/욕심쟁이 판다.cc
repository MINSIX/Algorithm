#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int N;
vector<vector<int>> arr, dp;

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y]; 
    dp[x][y] = 1; 
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        
        if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
        if (arr[xx][yy] > arr[x][y]) { 
            dp[x][y] = max(dp[x][y], 1 + dfs(xx, yy)); 
        }
    }
    
    return dp[x][y];
}

int main() {
    cin >> N;
    arr.resize(N, vector<int>(N));
    dp.resize(N, vector<int>(N, -1)); 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result = max(result, dfs(i, j)); 
        }
    }

    cout << result << endl; 
    return 0;
}
