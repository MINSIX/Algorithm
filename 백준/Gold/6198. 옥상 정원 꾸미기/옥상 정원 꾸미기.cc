#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    stack<int> st;
    int now;
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> now;
        while (!st.empty()) {
               
            if (st.top() > now)
            {
                cnt += st.size();
                break;
            }
            else {
                st.pop();
            }
        }

        st.push(now);
    }

    cout << cnt << endl;
    return 0;
}
