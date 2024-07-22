#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr[1001];
int match[1001];
bool visited[1001];

bool dfs(int n) {
    for (int i = 0; i < arr[n].size(); i++) {
        int a = arr[n][i];
        if (visited[a]) continue;
        visited[a] = true;
        if (match[a] == 0 || dfs(match[a])) {
            match[a] = n;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            arr[i].push_back(b);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        fill(visited, visited + M + 1, false); 
        if (dfs(i))
            cnt++;
    }
    cout << cnt;

    return 0;
}
