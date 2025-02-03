#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<pair<int,int>> st;

    for(int i = 0; i < N; i++){
        while(!st.empty() && st.top().first <= arr[i]){
            st.pop();
        }

        if(st.empty()) {
            cout << 0 << " ";
        } else {
            cout << st.top().second + 1 << " ";
        }

        st.push({arr[i], i});
    }

}
