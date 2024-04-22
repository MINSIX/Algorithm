#include<bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<bool>check(1000002, false);
    vector<bool>number(10, false);
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        number[num] = true;
    }


    for (int i = 0; i < 1000000; i++) {
        string s = to_string(i);
        for (int j = 0; j < s.size(); j++) {
            if (number[s[j] - '0'] == true) {
                check[i] = true;
                break;
            }
        }
    }
    int mini = 1000000002;
    int index = 1000000002;
    for (int i = 0; i < 1000002; i++) {
        if (check[i] == false) {
            if (i < n) {
                if (mini > n - i) {
                    mini = n - i;
                    index = i;
                }
            }
            else if (i == n) {
                mini = 0;
                index = i;
            }
            else {
                if (mini > i - n) {
                    mini = i - n;
                    index = i;
                }
            }
 
        }
    }
    string val = to_string(index);

    int sum1 = mini + val.size();
    int sum2 = 0;
    if (n >= 100) sum2 = n - 100;
    else sum2 = 100 - n;

    int ans = min(sum1, sum2);

    cout << ans;
}