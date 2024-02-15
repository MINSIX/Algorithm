#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int k, bb;

    for (int i = 0; i < N; i++) {
        cin >> k >> bb;

        vector<vector<int>> arr(k + 1, vector<int>(bb + 1, 0));
        
        for (int t = 1; t <= bb; t++) {
            arr[0][t] = t;
        }
          for (int t = 1; t <= k; t++) {
            arr[t][1] =1;
        }

        for (int t = 1; t <= k; t++) {
            for (int j = 2; j <= bb; j++) {
                arr[t][j] = arr[t][j - 1] + arr[t - 1][j];
            }
        }
  
     
        cout << arr[k][bb] << endl;

    }





    return 0;
}