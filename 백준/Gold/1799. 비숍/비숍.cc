#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
vector<pair<int, int>> whiteBishop, blackBishop;
vector<bool> d1, d2;

int BT(vector<pair<int, int>>& bishop, int idx, int cnt) {
    if (idx == bishop.size()) {
        return cnt;
    }
    int r = bishop[idx].first;
    int c = bishop[idx].second;
    int res = 0;
    if (!d1[r + c] && !d2[r - c + board.size() - 1]) {
        d1[r + c] = d2[r - c + board.size() - 1] = true;
        res = BT(bishop, idx + 1, cnt + 1);
        d1[r + c] = d2[r - c + board.size() - 1] = false;
    }
    res = max(res, BT(bishop, idx + 1, cnt));
    return res;
}

int main() {
    int N;
    cin >> N;
    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                if ((i + j) % 2 == 0) {
                    whiteBishop.push_back({i, j});
                } else {
                    blackBishop.push_back({i, j});
                }
            }
        }
    }

    d1.resize(2 * N, false);
    d2.resize(2 * N, false);

    int whiteCount = BT(whiteBishop, 0, 0);
    
    fill(d1.begin(), d1.end(), false);
    fill(d2.begin(), d2.end(), false);
    
    int blackCount = BT(blackBishop, 0, 0);

    cout << whiteCount + blackCount;
    return 0;
}