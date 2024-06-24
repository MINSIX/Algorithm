#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int S, P;
    cin >> S >> P;
    string s;
    cin >> s;
    int A, C, G, T;
    cin >> A >> C >> G >> T;

    int cnt = 0; map<char, int> arr;
    
    int now = 0;
    
    for (int i = 0; i < s.length();i++) {
        if (now < P) {
            arr[s[i]]++;
            now++;
            if(now==P)
                if (arr['A'] >= A && arr['C'] >= C && arr['G'] >= G && arr['T'] >= T)
                    cnt++;
        }
        else if (now == P) {
            arr[s[i]]++;
            arr[s[i - P]]--;
        

        if (arr['A'] >= A && arr['C'] >= C && arr['G'] >= G && arr['T'] >= T)
            cnt++;
        }
       
    }
    cout << cnt;


    return 0;
}
