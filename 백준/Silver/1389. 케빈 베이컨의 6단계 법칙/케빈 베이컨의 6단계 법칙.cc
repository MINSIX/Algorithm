#include<bits/stdc++.h>
using namespace std;
int N, M;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    int a, b;
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (k == i)
                continue;

            for (int j = 1; j <= N; j++) {

                if (i == j || k == j)
                    continue;


                if (arr[i][k] != 0 && arr[k][j] != 0) {
                    if (arr[i][j] != 0)
                        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                    else
                        arr[i][j] = arr[i][k] + arr[k][j];

                }

            }
        }
    }
    int manyfriend = 9999999;
    int svindex = 0;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum += arr[i][j];
        
        
        }
        if (manyfriend>sum) {
            manyfriend = sum;
            svindex = i;
        }
        sum = 0;
    }

    cout << svindex << endl;


}
