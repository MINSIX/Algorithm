#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<vector<int>>arr;

bool ck(int x, int y) {
    for (int i = x+1; i < N; i++) {
        if(!arr[i][y])
        for (int j = y+1; j < M; j++) {
            if (!arr[x][j] && arr[i][j])
                return false;



        }
    }

    return true;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    arr.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];


        }
    }

    if (N == 1) {
        cout << "YES";
        return 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j]) {
                if (!ck(i, j)) {
                    cout << "NO";
                    return 0;
                }


        }
        
        }
    }
    cout << "YES";




}
