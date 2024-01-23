#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


int N, M;
vector<int> arr;
vector<int> st;
void gt(int N, int M,  int current,vector<bool>& sv) {
  
    if (arr.size() == M)
    {
        for (int num : arr) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i =current; i <= N; ++i) {
        if(!sv[i])
        {
            sv[i] = true;
            arr.push_back(st[i]);
        gt(N, M, current,sv);
        sv[i] = false;
        arr.pop_back();
        }
    }
    }
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    st.push_back(0);
    cin >> N>>M;
    int s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        st.push_back(s);
    }
    sort(st.begin(), st.end());
    vector<bool> sv(N + 1, false);
    gt(N, M, 1,sv);

    return 0;
}



