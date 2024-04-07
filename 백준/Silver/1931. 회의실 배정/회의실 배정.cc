#include<bits/stdc++.h>

using namespace std;
int N;
bool comp(pair<int, int>& a, pair<int, int>b) {

    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vector<pair<int, int>>sche;
    int a, b;
    for (int i = 1; i <= N; i++) {
        cin >> a >> b;
        sche.push_back({ a,b });
    }

    sort(sche.begin(), sche.end(), comp);
    
    int cnt = 1;
    int nowst = sche[0].first;
    int nowed = sche[0].second;
    for (int i = 1; i < N; i++) {
        if (nowed > sche[i].first) {
            continue;
        }
        else {
            nowst = sche[i].first;
            nowed = sche[i].second;
            cnt++;
                 
        }

    }
    cout << cnt << endl;


}
