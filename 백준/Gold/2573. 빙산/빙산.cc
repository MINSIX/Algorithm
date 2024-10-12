#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int N, M;
vector<vector<int>> arr;

int countIcebergChunks() {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int chunkCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] > 0 && !visited[i][j]) {
   
                chunkCount++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 && ny >= 0 && nx < N && ny < M && arr[nx][ny] > 0 && !visited[nx][ny]) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }

    return chunkCount;
}

int main() {
    cin >> N >> M;
    arr.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int years = 0;
    while (true) {
        int chunks = countIcebergChunks();
        if (chunks >= 2) {

            cout << years << endl;
            return 0;
        }
        if (chunks == 0) {

            cout << 0 << endl;
            return 0;
        }

        vector<vector<int>> nextArr = arr; 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] > 0) {
                    int seaCount = 0;
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (nx >= 0 && ny >= 0 && nx < N && ny < M && arr[nx][ny] == 0) {
                            seaCount++;
                        }
                    }
                    nextArr[i][j] = max(0, arr[i][j] - seaCount);  
                }
            }
        }

        arr = nextArr;  
        years++;
    }

    return 0;
}
