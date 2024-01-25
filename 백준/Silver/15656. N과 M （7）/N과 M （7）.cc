#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


int N, M;
vector<int> arr;
vector<int> st;
void gt(int N, int M, int current) {

    if (arr.size() == M)
    {
        for (int num : arr) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i =1; i <= N; ++i) {
      
            arr.push_back(st[i]);
            gt(N, M, current);
          
            arr.pop_back();
      
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    st.push_back(0);
    cin >> N >> M;
    int s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        st.push_back(s);
    }
    sort(st.begin(), st.end());
   
    gt(N, M, 1);

    return 0;
}



