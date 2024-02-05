#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


int N, M,X;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> X;

    int st, ed, t;
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, -1));
    for (int i = 0; i < M; i++) {
        cin >> st >> ed >> t;
        arr[st][ed] = t;

    }
    int maxmin = 0;
    for (int k = 1; k <= N; k++)
    {
    for (int i = 1; i <= N; i++)
    {
        if (i == k)
            continue;
            for (int j = 1; j <= N; j++)
            {
                if (k == j || j == i)
                    continue;
            
                if (arr[i][k] != -1 && arr[k][j] != -1)
                    if (arr[i][j] == -1)
                        arr[i][j] = arr[i][k] + arr[k][j];
                    else
                    {
                        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

                    }
     
                
                   
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        maxmin = max(arr[i][X] + arr[X][i], maxmin);
    }
    cout << maxmin << endl;

    return 0;
}



