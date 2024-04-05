#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int N, M;

vector<int>times(100001, -1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    times[N] = 0;
    deque<int> q;
    q.push_back(N);
    int now = N;
    //if (N == M) {
    //    cout << 0;
    //    return 0;
    //}
    //if (M == 0){  cout << N;
    //return 0;
    //}

    while (!q.empty())
    {
        now = q.front();
        q.pop_front();
        for (int cnt : {now * 2,now - 1,  now + 1}) {
            if (cnt < 0 || cnt>100000)
                continue;
            if (times[cnt] != -1 && times[cnt] <= times[now] + 1)
                continue;
            if (cnt != now * 2) {
                times[cnt] = times[now] + 1;
                q.push_back(cnt);
            }
            else {
                times[cnt] = times[now];
                q.push_front(cnt);
            }
        }

    }

    cout << times[M];

    return 0;
}