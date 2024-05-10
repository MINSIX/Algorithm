#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int N;
const int INF = 1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>>arr;

    int x, y;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        arr.push_back({ x,y });

    }
    int mini = INF;
    int maxi = -INF;
    for (int i = 0; i < arr.size(); i++) {
        maxi = max(maxi, arr[i].first + arr[i].second);
        mini = min(mini, arr[i].first + arr[i].second);

    }
    int a = maxi - mini;
    mini = INF;
    maxi = -INF;
    for (int i = 0; i < arr.size(); i++) {
        maxi = max(maxi, arr[i].first - arr[i].second);
        mini = min(mini, arr[i].first - arr[i].second);

    }
    int b = maxi - mini;
    cout << max(a, b) << endl;



        return 0;
}