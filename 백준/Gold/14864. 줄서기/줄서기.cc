#include<bits/stdc++.h>
using namespace std;
int N, M;

const double INF = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    int x, y;

    vector<pair<int, int>>rules;
    vector<int> arr(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        arr[x]++;
        arr[y]--;
    }

    vector<int>check = arr;
    sort(check.begin(), check.end());

    for (int i = 1; i <= N; i++) {
        if (check[i] == check[i - 1]) {
            cout << -1<<endl;
            return 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << " ";
    }
    


}
