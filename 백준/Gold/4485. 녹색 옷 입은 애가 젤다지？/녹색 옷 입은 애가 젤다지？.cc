#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int ppcnt = 0;

    while (true) {
        cin >> N;
        if (N == 0) break;
        ppcnt++;

        vector<vector<int>> arr(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }

        vector<vector<int>> minRupee(N, vector<int>(N, 1e9));
        minRupee[0][0] = arr[0][0];

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({arr[0][0], {0, 0}});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == N - 1 && y == N - 1) {
                cout << "Problem " << ppcnt << ": " << cost << "\n";
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                    int newCost = cost + arr[nx][ny];
                    if (newCost < minRupee[nx][ny]) {
                        minRupee[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
    }

    return 0;
}
