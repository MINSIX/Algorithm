#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
vector<int> arr(N);
vector<int> real(N);
    

    for (int i = 0; i < N; i++)
        cin >> real[i];

    sort(real.begin(), real.end());
    for (int i = 0; i < N; i++) {
        if(i%2==0){
          arr[i/2]=real[i];
        }else{
          arr[N-(i+1)/2]=real[i];
       
        }
        
        
        
    }

    long long cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        cnt += arr[i] * arr[i + 1];
    }
    cnt += arr[0] * arr[N - 1];

    cout << cnt << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    return 0;
}
