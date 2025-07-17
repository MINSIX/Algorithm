#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    cin >> N;
    int maxlong = 0;

    for (int i = 0; i < N.size(); i++) {
        int sv = 0;
        for (int j = 1; (2 * j + i) <= N.size(); j++) {  
            int leftSum = 0, rightSum = 0;
            for (int k = i; k < i + j; k++) {
                leftSum += N[k] - '0';
            }
            for (int k = i + j; k < i + 2 * j; k++) {
                rightSum += N[k] - '0';
            }

            if (leftSum == rightSum) {
                sv = j;
            }
        }
        maxlong = max(maxlong, sv);
    }

    cout << maxlong * 2; 
}
