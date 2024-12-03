#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) 
        cin >> arr[i];

    int M;
    cin >> M;
    vector<int> arr2(M);
    for(int i = 0; i < M; i++) 
        cin >> arr2[i];

    sort(arr.begin(), arr.end(),greater<int>());
    sort(arr2.begin(), arr2.end(),greater<int>());

   if(arr[0] < arr2[0]) {
        cout << -1;
        return 0;
    }

    int time = 0;
   
    vector<bool> visited(M, false);
    int moved = 0;

    while(moved < M) {
        int idx = 0; 
        for(int i = 0; i < N; i++) {
            while(idx < M) {
                if(!visited[idx] && arr[i] >= arr2[idx]) {
                    visited[idx] = true;
                    moved++;
                    idx++;
                    break;
                }
                idx++;
            }
        }
        time++;
    }

    cout << time;
}
