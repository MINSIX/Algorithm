#include<bits/stdc++.h>
using namespace std;

long long ans = -1;
int N, cnt = 0;

void calculate(long long num, int size) {
    if (size == 0) {
        if (cnt == N) ans = num;
        cnt++;
        return;
    }

    int last = num % 10;
    if (num == 0) last = 10;

    for (int i = 0; i < last; i++) {
        if (num == 0 && i == 0) continue;
        calculate(num * 10 + i, size - 1);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i <= 10; i++) {
        calculate(0, i);
    }
    cout << ans;
}
