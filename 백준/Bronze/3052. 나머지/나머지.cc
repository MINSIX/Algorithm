#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    map<int, int>mm;
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >>a;
        if (!mm[a % 42]) {
            cnt++;
            mm[a % 42]++;
        }

    }

    cout << cnt << endl;


}



