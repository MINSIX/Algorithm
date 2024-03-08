#include<bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    vector<int> arr(a + 1, INF);
    vector<int> sum1(a + 1, INF);
    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
        if (i == 0)
            sum1[i] = arr[i];
        else
            sum1[i] = arr[i] + sum1[i - 1];
    }
    
  
    vector<int> cnt(a + 1, INF);
    int i = 0;
    for (int now = 0; now < a; now++) {
       
        if (sum1[now] >= b) {

            while (sum1[now] - sum1[i] >= b) {
                i++;
            }
            i--;
            cnt.push_back(now - i);

       }

    }
    int solve = *min_element(cnt.begin(), cnt.end());
    if (solve == INF)
        cout << 0 << endl;
    else
    cout << solve << endl;
   

}