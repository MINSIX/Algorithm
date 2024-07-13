#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << 10000 + a * 1000;
    }
    else if (a == b || b == c||c==a) {
        if (a == b)
            cout << 1000 + 100 * a;
        else if(b==c)
            cout << 1000 + 100 * c;
        else if (a == c)
            cout << 1000 + 100 * c;

    }
    else {
        cout << max({ a,b,c }) * 100;
    }


    return 0;
}
