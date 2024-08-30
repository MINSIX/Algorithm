#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(N, vector<int>(M));
    vector<vector<int>> group(N, vector<int>(M, -1));
    vector<int> groupSize;
    char a;
    for (int i = 0; i < N; i++) {
     
        for (int j = 0; j < M; j++) {
          cin >> a;
             arr[i][j] = a-'0';
        }
    }

    int groupId = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0 && group[i][j] == -1) {
                int size = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                group[i][j] = groupId;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    size++;

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && ny >= 0 && nx < N && ny < M && arr[nx][ny] == 0 && group[nx][ny] == -1) {
                            group[nx][ny] = groupId;
                            q.push({nx, ny});
                        }
                    }
                }

                groupSize.push_back(size);
                groupId++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1) {
                set<int> adjacentGroups;
                int totalSize = 1;

                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    if (ni >= 0 && nj >= 0 && ni < N && nj < M && arr[ni][nj] == 0) {
                        adjacentGroups.insert(group[ni][nj]);
                    }
                }

                for (int gid : adjacentGroups) {
                    totalSize += groupSize[gid];
                }

                cout << totalSize % 10;
            } else {
                cout << 0;
            }
        }
        cout << '\n';
    }

    return 0;
}
