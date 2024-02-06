#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int N, K, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d", &N);
    vector<int> pnum(1000001, 0);
    vector<int> mnum(1000001, 0);
    int zero = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d",&M);
        if (M > 0)
            pnum[M]++;
        else if (M < 0)
            mnum[-M]++;
        else
            zero++;
   }
    int i = 1000000;
    while (i >= 1) {
        while (mnum[i] > 0) {
            printf("%d\n", -i);
            mnum[i]--;
        }
        i--;
    }
    while (zero > 0)
    {
        printf("0\n");
        zero--;
    }
    while (i <= 1000000) {
        while (pnum[i] > 0) {
            printf("%d\n", i);
            pnum[i]--;
        }
        i++;
    }


    return 0;
}



