#include <bits/stdc++.h>
using namespace std;
  int R, C;
int dy[3] = {-1, 0, 1};
int cnt = 0;
bool dfs(int x, int y, vector<vector<char>> &arr) {
    if (y == C - 1) {
        cnt++;
        return true;
    }

    for (int t = 0; t < 3; t++) {
        int xx = x + dy[t];
        int yy = y + 1;

        if (xx < 0 || xx >= arr.size() || yy >= C || arr[xx][yy] != '.') {
            continue;
        }

        arr[xx][yy] = '#'; 
        if (dfs(xx, yy, arr)) {
            return true;
        }
    }

    return false;
}

int main() {
  
    cin >> R >> C;
    vector<vector<char>> arr(R, vector<char>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }



    for (int i = 0; i < R; i++) {
        if (arr[i][0] == '.') {
            arr[i][0] = '#'; 
            dfs(i, 0, arr);
        }
    }

    cout << cnt;

}
