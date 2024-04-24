#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

// 유효한 퀸 배치인지 확인하는 함수
bool isValid(vector<int>& queens, int row, int col) {


    for (int i = 0; i < row; i++) {
        if (queens[i] == col || abs(row - i) == abs(col - queens[i]))
            return false;
    }
    return true;
}


void solveNQueens(vector<int>& queens, int row, int n) {
    if (row == n) { 
        cnt++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isValid(queens, row, col)) {
            queens[row] = col;
            solveNQueens(queens, row + 1, n); 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> queens(N); // 퀸의 위치를 저장하는 배열

    solveNQueens(queens, 0, N); // N-퀸 문제 해결 함수 호출

    cout << cnt << endl; // 가능한 배치의 수 출력

    return 0;
}
