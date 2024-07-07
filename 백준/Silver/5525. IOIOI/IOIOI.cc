#include <bits/stdc++.h>
using namespace std;

long long N, M;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> M;
    cin >> s;

    int cnt = 0;


    for (int i = 0; i < M; ++i) {
        if (s[i] == 'I') {
            int pcnt = 0;

            while (i + 1 < M && s[i + 1] == 'O' && i + 2 < M && s[i + 2] == 'I') {
                pcnt++;
                i += 2;
            }

            if (pcnt >= N) {
                cnt += (pcnt - N + 1);
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
