#include<bits/stdc++.h>
using namespace std;
int N, M;

int check(string s) {
    int st = 0;
    int ed = s.size() - 1;
    while (st<ed) {
        if(s[st]!=s[ed])
        return s.size();
        st++;
        ed--;
    }

    st = 0;

    ed = s.size() - 2;
    while (st < ed) {
        if (s[st] != s[ed])
            return s.size()-1;
        st++;
        ed--;
    }
    

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;

    cin >> s;
    cout << check(s) << endl;


        return 0;
}
