#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string p;
    cin >> s;
    cin >> p;

    int cnt = 0;
    int i = 0;

    while (i < p.length()) {
        int max_len = 0; 

        for (int j = 0; j < s.length(); j++) {
            int len = 0;
            while (i + len < p.length() && j + len < s.length() && s[j + len] == p[i + len]) {
                len++;
            }
            max_len = max(max_len, len);
        }

        i += max_len;
        cnt++;
    }

    cout << cnt;

}
