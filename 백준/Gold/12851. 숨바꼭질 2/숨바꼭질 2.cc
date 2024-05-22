#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int N, M;

int arr[100002];
int cnt[100002]; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    if (N == M) {
        cout << 0 << "\n" << 1 << endl;
        return 0;
    }
    fill(arr, arr + 100002, -1); 
    arr[N] = 0;
    cnt[N] = 1;
    queue<int> q;
    q.push(N);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int next : {now + 1, now - 1, now * 2}) {
            if (next < 0 || next > 100000)
                continue;

            if (arr[next] != -1) {
                if (arr[now] + 1 == arr[next])
                    cnt[next] += cnt[now]; 
            }
            else {
                arr[next] = arr[now] + 1;
                cnt[next] = cnt[now];
                q.push(next);
            }
        }
    }
    cout << arr[M] << "\n" << cnt[M] << endl;
    return 0;
}
