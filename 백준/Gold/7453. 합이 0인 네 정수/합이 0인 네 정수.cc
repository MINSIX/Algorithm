#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    long long cnt = 0;
    vector<long long> a(N + 1);
    vector<long long> b(N + 1);
    vector<long long> c(N + 1);
    vector<long long> d(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<long long> ab(N * N);
    vector<long long> cd(N * N);

    int id = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ab[id] = a[i] + b[j];
            cd[id] = c[i] + d[j];
            id++;
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    int w = 0, t = N * N - 1;
    while (w < N * N && t >= 0) {
        if (ab[w] + cd[t] > 0) 
            t--;
         else if (ab[w] + cd[t] < 0) 
            w++;
        else {
            int cnta = 1, cntb = 1;
            while (w + cnta < N * N && ab[w + cnta] == ab[w]) cnta++;
            while (t - cntb >= 0 && cd[t - cntb] == cd[t]) cntb++;
            cnt += static_cast<long long>(cnta) * cntb;
            w += cnta;
            t -= cntb;
        }
    }
    
    cout << cnt;
    return 0;
}
