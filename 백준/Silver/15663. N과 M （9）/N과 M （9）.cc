#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


int N, M;
vector<int> arr;
vector<int>sv;
int visited[10001] = { 0, };
void gt(int N, int M,  int current) {
  
    if (arr.size() == M)
    {
        for (int num : arr) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }
    int check = 0;
    for (int i =1; i <= N; ++i) {
        if (check != sv[i]&&visited[sv[i]]>0) {
            check = sv[i];
            visited[sv[i]]--;
            arr.push_back(sv[i]);
            gt(N, M, i);
            visited[sv[i]]++;
            arr.pop_back();
        }
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
        visited[s]++;
        sv.push_back(s);
    }
    sort(sv.begin(), sv.end());
  
    gt(N, M, 1);

    return 0;
}



