#include <bits/stdc++.h>
using namespace std;

int ans = 1e9;
int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int cal(const vector<pair<int, int>>& selected_chickens) {
    int su = 0;
    for (auto& hou : house) {
        int sv = 1e9;
        for (auto& chick : selected_chickens) {
            sv = min(sv, abs(chick.first - hou.first) + abs(chick.second - hou.second));
        }
        su += sv;
    }
    return su;
}

void solve() {
    vector<int> indices(chicken.size());
    fill(indices.end() - M, indices.end(), 1);
    
    do {
        vector<pair<int, int>> selected_chickens;
        for (int i = 0; i < chicken.size(); ++i) {
            if (indices[i]) {
                selected_chickens.push_back(chicken[i]);
            }
        }
        ans = min(ans, cal(selected_chickens));
    } while (next_permutation(indices.begin(), indices.end()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                house.push_back({i, j});
            else if (arr[i][j] == 2)
                chicken.push_back({i, j});
        }
    }

    solve();
    cout << ans << endl;

    return 0;
}
