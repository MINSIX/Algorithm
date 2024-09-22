#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


int N, M;
vector<int> arr;
void gt(int N, int M,  int current) {
    if (arr.size() == M)
    {
        for (int num : arr) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = current; i <= N; ++i) {
 
        arr.push_back(i);
        gt(N, M, i + 1);
        arr.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N>>M;
  gt(N, M, 1);

    return 0;
}



