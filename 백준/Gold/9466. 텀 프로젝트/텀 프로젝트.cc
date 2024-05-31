#include <bits/stdc++.h>
using namespace std;

int T;
vector<int> arr;
vector<bool> visited, finished;
int cnt;

void dfs(int node) {
    visited[node] = true;
    int next = arr[node];

    if (!visited[next])
        dfs(next);
    else if (!finished[next]) {
        for (int i = next; i != node; i = arr[i])
            cnt--;
        cnt--;
    }

    finished[node] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        arr.resize(N + 1);
        visited.assign(N + 1, false);
        finished.assign(N + 1, false);
        cnt = N;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
