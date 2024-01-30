#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int N,M;



int arr[101][101] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> M;

    int a, b, c;
    for (int i = 0; i <M; i++) {
        cin >> a >> b >> c;
        if(arr[a][b]>c||arr[a][b]==0)
        arr[a][b] = c;
    }
   
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (i == k)
                continue;
            for (int j = 1; j <= N; j++) {
                if (j == k || j == i)
                    continue;

                if (arr[i][j] != 0 && arr[i][k] != 0 && arr[k][j] != 0)
                    arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
                else if (arr[i][k] != 0 && arr[k][j] != 0)
                    arr[i][j] = arr[i][k]+arr[k][j];
         

            }
        }
    }


    for (int i = 1; i <= N; i++) {
   
        for (int j = 1; j <= N; j++) {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }

    return 0;
}



