#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long double sum = 0;
    scanf("%d", &N);
    N -= 2;
    long long x1, y1, x2, y2;
    scanf("%lld %lld", &x1, &y1);
    scanf("%lld %lld", &x2, &y2);

    while (N--) {
        long long x3, y3;
        scanf("%lld %lld", &x3, &y3);
        sum += (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2.0;
        x2 = x3; y2 = y3;
    }
    printf("%.1Lf", fabsl(sum));
    return 0;
}
