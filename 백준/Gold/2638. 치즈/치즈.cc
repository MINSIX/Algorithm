#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int N, M;
vector<vector<int>> arr;
vector<vector<bool>> air;

void updateAir() {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    q.push({0, 0});
    visited[0][0] = true;
    air[0][0] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx < 0 || yy < 0 || xx >= N || yy >= M)
                continue;

            if(!visited[xx][yy] && arr[xx][yy] == 0) {
                visited[xx][yy] = true;
                air[xx][yy] = true;
                q.push({xx, yy});
            }
        }
    }
}

bool ck(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx < 0 || yy < 0 || xx >= N || yy >= M)
            continue;

        if(arr[xx][yy] == 0 && air[xx][yy])
            cnt++;
    }

    return cnt >= 2;
}

int main() {
    cin >> N >> M;

    arr.resize(N, vector<int>(M));
    air.resize(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int timecnt = 0;

    while(true) {

        updateAir();

        queue<pair<int, int>> q;
        int cnt = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(arr[i][j] == 1 && ck(i, j)) {
                    q.push({i, j});
                    cnt++;
                }
            }
        }

        if(cnt == 0) 
            break;

        while(!q.empty()) {
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            arr[xx][yy] = 0;
        }

        timecnt++;
    }

    cout << timecnt << endl;

    return 0;
}
