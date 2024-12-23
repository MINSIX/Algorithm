#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    int cnt = -1; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int q = -N; q < N; q++) {
                for (int p = -M; p < M; p++) {
                    if (q == 0 && p == 0) 
                        continue;
                    int row = i, col = j;
                    int num = 0;
                    while (0 <= row && row < N && 0 <= col && col < M) {
                        num = num * 10 + arr[row][col];
                        int root = sqrt(num);
                        if (root * root == num) { 
                            cnt = max(cnt, num);
                        }
                        row += q;
                        col += p; 
                    }
                }
            }
        }
    }
    cout << cnt;
}
