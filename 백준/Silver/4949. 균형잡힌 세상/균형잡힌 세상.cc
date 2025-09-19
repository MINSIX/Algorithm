#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while (getline(cin, s)) {
        if (s == ".") break;

        stack<char> st;
        bool flag = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            }
            else if (s[i] == ')') {
                if (st.empty() || st.top() != '(') {
                    cout << "no\n";
                    flag = true;
                    break;
                }
                st.pop();
            }
            else if (s[i] == ']') {
                if (st.empty() || st.top() != '[') {
                    cout << "no\n";
                    flag = true;
                    break;
                }
                st.pop();
            }
        }

        if (flag) continue;

        if (!st.empty()) cout << "no\n";
        else cout << "yes\n";
    }
}
