#include <bits/stdc++.h>
using namespace std;

int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;


    vector<vector<int>>arr(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];


        }
    }
    if (arr[N - 1][N - 1] == 1)
    {       cout << 0 << endl;
    return 0;
}int cnt = 0;

    queue<pair<pair<int, int>, int>>q;
    q.push({ { 0,1 }, 0});
    while (!q.empty()) {
        int nowx = q.front().first.first;
        int nowy = q.front().first.second;
        int di = q.front().second;
        q.pop();
        for (int i = 0; i < 3; i++) {
            if(di==0)
                if (i == 1)
                    continue;
            
            if (di == 1)
                if (i == 0)
                    continue;
            
            
            int xx = nowx + dx[i];
            int yy = nowy + dy[i];


         

            if (xx >= N || yy >= N)
                continue;
            if (arr[xx][yy] == 1)
                continue;

            if (i == 2)
                if (arr[nowx + 1][nowy] == 1 || arr[nowx][nowy + 1] == 1)
                    continue;
          

               if (xx == N - 1 && yy == N - 1)
            {
                cnt++;
                continue;
            }


            q.push({ { xx, yy }, i });
        }

    }



    cout << cnt << endl;



    return 0;
}
