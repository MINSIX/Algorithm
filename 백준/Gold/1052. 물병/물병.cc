#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int addBottles = 0;
    while (1) {
        int count = 0;
        int temp = N;

        while (temp > 0) {
            if (temp % 2 == 1) count++;
            temp /= 2;
        }

        if (count <= K) break;

        N++;
        addBottles++;
    }

    cout << addBottles; 
}
