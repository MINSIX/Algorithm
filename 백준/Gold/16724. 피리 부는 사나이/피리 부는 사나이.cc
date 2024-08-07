#include <bits/stdc++.h>
using namespace std;

enum {U = 0, D, L, R}; 
int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1}; 

int directionIndex(char c) {
    if (c == 'U') return U;
    if (c == 'D') return D;
    if (c == 'L') return L;
    if (c == 'R') return R;
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> map(N, vector<char>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<bool>> inStack(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j]) {
                stack<pair<int, int>> st;
                vector<pair<int, int>> nodes;
                bool hasCycle = false;

                st.push({i, j});
                visited[i][j] = true;
                inStack[i][j] = true;

                while (!st.empty()) {
                    int nowX = st.top().first;
                    int nowY = st.top().second;
                    st.pop();
                    nodes.push_back({nowX, nowY});
                    
                    int dir = directionIndex(map[nowX][nowY]);
                    int nx = nowX + dx[dir];
                    int ny = nowY + dy[dir];
                    
               
                    
                    if (inStack[nx][ny]) {
                        hasCycle = true;
                    } else if (!visited[nx][ny]) {
                        visited[nx][ny] = true;
                        inStack[nx][ny] = true;
                        st.push({nx, ny});
                    }
                }
                
               
                for (const auto& node : nodes) {
                    inStack[node.first][node.second] = false;
                }
                
                if (hasCycle) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt<< endl;
    return 0;
}
