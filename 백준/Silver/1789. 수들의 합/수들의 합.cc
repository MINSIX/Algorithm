#include<bits/stdc++.h>
using namespace std;

int main() {
    long long S;
    cin >> S;
    long long total = 0;
    long long i = 1;
    while (total + i <= S) {
        total += i;
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}
