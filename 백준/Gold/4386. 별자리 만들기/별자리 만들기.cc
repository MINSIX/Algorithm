#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N;
vector<int> group;

double getGroup(int n) {
    if (group[n] == n)
        return n;
    return group[n] = getGroup(group[n]);
}

void joinGroup(int a, int b) {
    a = getGroup(a);
    b = getGroup(b);
    if (a > b)
        swap(a, b);
    group[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    group.resize(N + 1);
    for (int i = 1; i <= N; i++)
        group[i] = i;

    vector<pair<double, double>> starts(N); // 별의 좌표
    vector<pair<double, pair<int, int>>> MST; // 간선 정보 (거리, (정점1, 정점2))

    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        starts[i] = { x, y };
    }

    // 각 별들 간의 거리를 계산하여 MST에 저장
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double dist = sqrt(pow(starts[i].first - starts[j].first, 2) + pow(starts[i].second - starts[j].second, 2));
            MST.push_back({ dist, { i + 1, j + 1 } });
        }
    }

    sort(MST.begin(), MST.end());

    double ans = 0;
    int cnt = 0;
    for (auto& edge : MST) {
        double dist = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (getGroup(u) == getGroup(v)) // 이미 같은 그룹에 속해있다면 사이클이 형성됨
            continue;

        joinGroup(u, v);
        ans += dist;
        cnt++;

        if (cnt == N - 1)
            break;
    }

    printf("%.2lf\n", ans);

    return 0;
}
