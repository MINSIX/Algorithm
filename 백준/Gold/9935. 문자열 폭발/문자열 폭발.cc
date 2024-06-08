#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    string p;
    stack<char> t;
    cin >> s;
    cin >> p;


    for (int i = 0; i < s.size(); i++) {
        t.push(s[i]);
        if (t.size() >= p.size()) {
            string temp = "";
            for (int j = 0; j < p.size(); ++j) {
                temp = t.top() + temp;
                t.pop();
            }
            if (temp != p) {
                for (int j = 0; j < p.size(); ++j) {
                    t.push(temp[j]);
                }
            }
        }
    }

    stack<char> real;
    while (!t.empty()) {
        real.push(t.top());
        t.pop();
    }

    if (real.empty())
        cout << "FRULA" << "\n";
    else
        while (!real.empty()) {
            cout << real.top();
            real.pop();
        }
    return 0;
}
