#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int N;
const int INF = 99999999;

int tsp(int current, int visited, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if (visited == (1 << N) - 1) {
        if (arr[current][0] != 0) // 시작 도시로 돌아갈 수 있는 경우에만 반환
            return arr[current][0];
        return INF; // 시작 도시로 돌아갈 수 없는 경우 무한대 반환
    }

    // 이미 계산한 값이 있는 경우 반환
    if (dp[current][visited] != -1) {
        return dp[current][visited];
    }

    int shortest = INF;

    // 모든 도시를 방문해보며 최단 거리를 갱신
    for (int i = 0; i < N; ++i) {
        // 이미 방문한 도시인 경우 건너뜀
        if (visited & (1 << i)) continue;
        if (arr[current][i] == 0) continue; 
        // 다음 도시를 방문하고 거리를 계산
        int distance = arr[current][i] + tsp(i, visited | (1 << i), arr, dp);

        // 현재까지의 최단 거리보다 더 짧은 거리를 발견한 경우 갱신
        shortest = min(shortest, distance);
    }

    // 계산한 값을 메모이제이션
    return dp[current][visited] = shortest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(N, vector<int>(1 << N, -1)); // 메모이제이션 배열 초기화

    int shortest_path = tsp(0, 1, arr, dp);
    printf("%d\n", shortest_path);

    return 0;
}