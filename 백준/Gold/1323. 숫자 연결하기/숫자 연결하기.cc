#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    int K;
    cin >> N >> K;

    int tmp = 0;
    int cnt = 0;
    set<int> st;

    while (1) {
        cnt++;
        for (char c : N) {
            tmp = (tmp * 10 + (c - '0')) % K;
        }

        if (tmp == 0) {
            cout << cnt;
            return 0;
        }

        if (st.find(tmp) != st.end()) {
            cout << -1;
            return 0;
        }

        st.insert(tmp);
    }
}
