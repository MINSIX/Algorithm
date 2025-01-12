#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    int N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int now = 1;
    queue<pair<int,int>> q;
    vector<pair<int,int>> sv;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j] && arr[i][j] != 0){
                visited[i][j] = true;
                arr[i][j] = now;
                q.push({i, j});
                while(!q.empty()){
                    auto [x, y] = q.front(); 
                    q.pop();
                    for(int t = 0; t < 4; t++){
                        int xx = x + dx[t];
                        int yy = y + dy[t];
                        if(xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
                        if(!visited[xx][yy] && arr[xx][yy] != 0){
                            visited[xx][yy] = true;
                            arr[xx][yy] = now;
                            q.push({xx, yy});
                        }
                    }
                }
                sv.push_back({i, j});
                now++;
            }
        }
    }

    int answer = 1e9;

     for(int i = 1; i < now; i++){
        vector<vector<int>> dist(N, vector<int>(N, -1));
        while(!q.empty()) q.pop();

         for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                if(arr[r][c] == i){
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int t = 0; t < 4; t++){
                int xx = x + dx[t];
                int yy = y + dy[t];
                if(xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
                   if(arr[xx][yy] != 0 && arr[xx][yy] != i){
                    answer = min(answer, dist[x][y]);
                    break;
                }

                 if(arr[xx][yy] == 0 && dist[xx][yy] == -1){
                    dist[xx][yy] = dist[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }
    }

    cout << answer;
}
