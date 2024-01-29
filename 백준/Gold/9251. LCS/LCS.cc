#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

int N;

string s;

string b;

int cal(const string& a, const string& b) {

    int m = s.length();

    int n = b.length();

    vector<vector<int>> arr(m + 1,vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            if (s[i - 1] == b[j - 1]) {

                arr[i][j] = arr[i - 1][j - 1] + 1;

            }

            else {

                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);

            }

        }

    }

    return arr[m][n];

}

int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

   

    cin >> s;

    cin >> b;

    

    cout << cal(s,b)<<endl;

    return 0;

}

