#include <bits/stdc++.h>
using namespace std;
int N;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    string s;
    char st, ed;
    N--;
    cin >> s;
    st = s[0];

    bool flag = true;
    while (N--) {
        cin >> s;
        if (s[0] != st)
        {
            flag = false;
        }
      
    }
    if (flag) {
        cout << 1 << endl;
    }
    else
        cout << 0 << endl;
}