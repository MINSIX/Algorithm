#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int h, w;
        cin >> h >> w;
        vector<vector<char>> arr(h, vector<char>(w));
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        queue<pair<int, int>> q;
        queue<pair<int, int>> door[26];  
        vector<bool> key(26, false);    

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
                if (i == 0 || j == 0 || i == h - 1 || j == w - 1) {
                    if (arr[i][j] == '.' || arr[i][j] == '$' || islower(arr[i][j])) {
                        q.push({i, j});
                        visited[i][j] = true;
                    } else if (isupper(arr[i][j])) {
                        door[arr[i][j] - 'A'].push({i, j});
                    }
                }
            }
        }

        string s;
        cin >> s;
        if (s != "0") {
            for (char c : s) {
               int k = c-'a';
                key[k] = true;
                while (!door[k].empty()) {
                        q.push(door[k].front());
                        door[k].pop();
                    }
            }
        }

        int cnt = 0; 

        while (!q.empty()) {
            int nowx = q.front().first;
            int nowy = q.front().second;
            q.pop();
            

   
            if (arr[nowx][nowy] == '$') cnt++;

            if (islower(arr[nowx][nowy])) {
                int k = arr[nowx][nowy] - 'a';
           
                    key[k] = true;

                    while (!door[k].empty()) {
                        q.push(door[k].front());
                        door[k].pop();
                    }
                
            }

            for (int i = 0; i < 4; i++) {
                int xx = nowx + dx[i];
                int yy = nowy + dy[i];

                if (xx < 0 || yy < 0 || xx >= h || yy >= w || visited[xx][yy]) continue;

                if (arr[xx][yy] == '*') continue;

                if (isupper(arr[xx][yy])) {
                    if (!key[arr[xx][yy] - 'A']) {
                        door[arr[xx][yy] - 'A'].push({xx, yy});
                        continue;
                    }
                }

                visited[xx][yy] = true;
                q.push({xx, yy});
            }
        }

        cout << cnt << "\n";
    }
}
