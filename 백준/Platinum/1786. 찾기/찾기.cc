#include <bits/stdc++.h>
using namespace std;
string s, p;
vector<int> pi;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	getline(cin, s);
    getline(cin, p);
    pi.resize(p.size()+1, 0);
    int n = strlen(s.c_str());
    int m = strlen(p.c_str());

  
    int i = -1, j = 0;
    pi[j] = i;
    while (j < m) {
        if (i == -1 || p[i] == p[j])
            pi[++j] = ++i;
        else
            i = pi[i];
    }
    i = 0, j = 0;
    vector<int> idx;
    int cnt = 0;


    while (i < n) {
        if (j == -1 || s[i] == p[j])
            i++, j++;
        else
            j = pi[j];

        if (j == m) {
            cnt++;
            idx.push_back(i-m+1);
            j = pi[j];
        }
    }
    cout << cnt << endl;
    for (auto i : idx) {
        cout << i << " ";


    }
	return 0;
}
