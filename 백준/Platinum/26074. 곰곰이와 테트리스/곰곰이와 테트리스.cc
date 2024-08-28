#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int a;
    for (int i = 0; i < 8; i++)
        cin >> a;

    if (N * M == 2)
        cout << "ChongChong";
    else
        cout << "GomGom";

}



