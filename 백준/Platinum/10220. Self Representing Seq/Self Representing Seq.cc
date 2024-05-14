#include <bits/stdc++.h>
using namespace std;
int N;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    int a;
    while (N--) {
        cin >> a;
        if (a == 1 || a == 2 || a == 3 || a == 6)
            cout << 0 << endl;
        else if (a == 4)
            cout << 2 << endl;
        else
            cout << 1 << endl;

      
    }
  
    return 0;
}