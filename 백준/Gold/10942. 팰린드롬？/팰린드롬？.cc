#include <bits/stdc++.h>
using namespace std;
int N;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<int>arr(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    vector<vector<bool>> pel(N + 1, vector<bool>(N + 1, false));
    for (int i = 1; i < N; i++)
    {
        pel[i][i] = true;
        if(arr[i]==arr[i+1])
        pel[i][i + 1] = true;
    }
    pel[N][N] = true;

    for (int i = N-1; i > 0; i--) {
        for (int j = i + 1; j <= N; j++) {
            if (arr[i] == arr[j] && pel[i + 1][j - 1] == true)
                pel[i][j] = true;
        }
    }

    int M,a,b;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        if (pel[a][b])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";


    }
    
}