#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int R, C;
    cin >> R >> C;
    vector<vector<char>> arr(R, vector<char>(C));
    queue<pair<int, int>> icetohosu;
    queue<pair<int, int>> swan, next_swan;
    int bakx, baky;

    bool foundSwan = false;

    // 초기화 작업
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'L') {
                if (!foundSwan) {
                    bakx = i;
                    baky = j;
                    swan.push({i, j});
                    foundSwan = true;
                  }
                }
            if (arr[i][j] != 'X') {
                icetohosu.push({i, j}); 
            }
        }
    }

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    visited[bakx][baky] = true;
    int days = 0;
    bool find = false;

    while (!find) {
        while (!swan.empty() && !find) {
            int swannowx = swan.front().first;
            int swannowy = swan.front().second;
            swan.pop();

            for (int i = 0; i < 4; i++) {
                int xx = swannowx + dx[i];
                int yy = swannowy + dy[i];

                if (xx < 0 || yy < 0 || xx >= R || yy >= C)
                    continue;

                if (visited[xx][yy])
                    continue;

                visited[xx][yy] = true;

                if (arr[xx][yy] == 'L') {
                    find = true;
                    break;
                }

                if (arr[xx][yy] == 'X') {
                    next_swan.push({xx, yy});
                } else {
                    swan.push({xx, yy});
                }
            }
        }

        if (find)
            break;

        int icetohosu_size = icetohosu.size();
        for (int i = 0; i < icetohosu_size; i++) {
            int nowx = icetohosu.front().first;
            int nowy = icetohosu.front().second;
            icetohosu.pop();

            for (int j = 0; j < 4; j++) {
                int xx = nowx + dx[j];
                int yy = nowy + dy[j];

                if (xx < 0 || yy < 0 || xx >= R || yy >= C)
                    continue;

                if (arr[xx][yy] == 'X') {
                    arr[xx][yy] = '.'; 
                    icetohosu.push({xx, yy});
                }
            }
        }

        swan = next_swan;
        while (!next_swan.empty()) {
            next_swan.pop();
        }

        days++;
    }

    cout << days;

    return 0;
}
