#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        string a;
        string b;
        cin >> a >> b;
        int cnt = 0;
        vector<int> apositiona;
        vector<int> apositionb;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 'a')
                apositiona.push_back(i);
            if (b[i] == 'a')
                apositionb.push_back(i);

            
        }
        for (int i = 0; i < apositiona.size(); i++) {

            cnt += abs(apositiona[i] - apositionb[i]);
        }

        cout << cnt << endl;
    }

    return 0;
}