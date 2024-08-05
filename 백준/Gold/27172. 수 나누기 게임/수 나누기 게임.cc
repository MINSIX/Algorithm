#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> point(1000001, 0);  
    vector<vector<int>> yaksoo(N);
    vector<bool> check(1000001, false);
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        check[arr[i]] = true;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 1; j * j <= arr[i]; j++) {
            if(arr[i] % j == 0) {
                yaksoo[i].push_back(j);
                if(j * j != arr[i]) 
                    yaksoo[i].push_back(arr[i] / j);
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(auto k : yaksoo[i]) {
            if(check[k])
                {point[k]++;
                point[arr[i]]--;
                }
        }
    }
    
    for(int i = 0; i < N; i++) {
        cout << point[arr[i]] << " ";
    }
    
    return 0;
}