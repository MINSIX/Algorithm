#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        unordered_map<string, int> m;
        vector<string>a;
        for (int i = 0; i < n; i++)
        {
            string s,c;
            cin >> s>>c;
            m[c]++;
        }
        long long sum = 1;
        for (auto it : m) {
            sum *= (it.second+1);

            }
        sum -= 1;
        cout << sum << '\n';

  
        }
     




    return 0;
}
