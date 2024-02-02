#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


int N, M;
vector<int> arr;
vector<int>sv;
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
 
        arr.push_back(sv[i]);
        gt(N, M, i);
        arr.pop_back();
    }
 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sv.push_back(0);
    int s;
    cin >> N>>M;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        sv.push_back(s);
    }
    sort(sv.begin(), sv.end());
  
    gt(N, M, 1);

    return 0;
}



