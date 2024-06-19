#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    long long P;
    cin >> N >> M >> P;


    vector<vector<int>>arr(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }


    for (int i = 0; i < N; i++) {
        sort(arr[i].begin(), arr[i].end());
    }
    for (int i = 0; i < N; i++) {
        int power = 0;
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == -1)
            {
                power++;
                continue;
            }

            if (arr[i][j] <= P)
                P += arr[i][j];
            else
            {

                while (arr[i][j] > P && power > 0) {
                    P *= 2;
                    power--;

                }
                if (arr[i][j] <= P)
                    P += arr[i][j];
            }
            if (arr[i][j] > P)
            {
                cout << 0;
                return 0;
            }

        }
        while (power-- > 0)
        {

            P *= 2;
            power--;
        }
    }
    cout << 1;




}
