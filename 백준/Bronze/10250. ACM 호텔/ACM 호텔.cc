#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c % a == 0) {

            cout << a * 100 + c / a << "\n";
        }
        else {
            cout << (c % a) * 100 + c / a + 1 << " \n";
        }


    }

    return 0;
}
