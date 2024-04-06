#include<bits/stdc++.h>

using namespace std;

int V; // 정점 개수
vector<int> group(100001);
bool comparex(const pair<int, pair<pair<int, int>, int>>& a, const pair<int, pair<pair<int, int>, int>>& b) {
    return a.second.first.first < b.second.first.first;
}
bool comparey(const pair<int, pair<pair<int, int>, int>>& a, const pair<int, pair<pair<int, int>, int>>& b) {
    return a.second.first.second < b.second.first.second;
}

bool comparez(const pair<int, pair<pair<int, int>, int>>& a, const pair<int, pair<pair<int, int>, int>>& b) {
    return a.second.second < b.second.second;
}
int getGroup(int n) {
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
    int a, b, c;

    cin >> V;

    vector<vector<int>> MST;
    vector<pair<int, pair<pair<int, int>, int>>> planet; // 좌표와 좌표의 인덱스 저장
    for (int i = 0; i < V; i++) {
        cin >> a >> b >> c;
        planet.push_back({ i, {{a, b}, c} }); // 좌표와 해당 좌표의 인덱스 저장
        group[i] = i;
    }

    sort(planet.begin(), planet.end(), comparex);
    for (int i = 0; i < V - 1; i++) {
        int range = abs(planet[i].second.first.first - planet[i + 1].second.first.first);
        MST.push_back({ range, planet[i].first, planet[i + 1].first });
    }


    sort(planet.begin(), planet.end(), comparey);
    for (int i = 0; i < V - 1; i++) {
        int range = abs(planet[i].second.first.second - planet[i + 1].second.first.second);
        MST.push_back({ range, planet[i].first, planet[i + 1].first });
    }

    sort(planet.begin(), planet.end(), comparez);
    for (int i = 0; i < V - 1; i++) {
        int range = abs(planet[i].second.second - planet[i + 1].second.second);
        MST.push_back({ range, planet[i].first, planet[i + 1].first });
    }

    sort(MST.begin(), MST.end());

    int cnt = 0, ans = 0;

    for (auto& ed : MST) {
        if (getGroup(ed[1]) == getGroup(ed[2]))
            continue;
        joinGroup(ed[1], ed[2]);
        ans += ed[0];
        cnt++;
        if (cnt == V - 1)
            break;
    }

    cout << ans << endl;
}
