#include <bits/stdc++.h>
using namespace std;

int N;
long long B;
vector<vector<int>> arr;

vector<vector<int>> cal(vector<vector<int>> Q,vector<vector<int>> T) {
    vector<vector<int>> result(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += Q[i][k] * T[k][j];
                result[i][j] %= 1000; 
            }
        }
    }
    
    return result;
}

vector<vector<int>> matrix_power(vector<vector<int>> matrix, long long power) {
    vector<vector<int>> result(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; i++) {
        result[i][i] = 1;
    }

    while (power > 0) {
        if (power % 2 == 1) {
            result = cal(result, matrix);
        }
        matrix = cal(matrix, matrix);
        power /= 2;
    }
    
    return result;
}

int main() {
    cin >> N >> B;
    arr.resize(N, vector<int>(N));
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    vector<vector<int>> result = matrix_power(arr, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
