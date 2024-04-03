#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int g, p;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> g;
    cin >> p;
    vector<int>gate(g + 1, 0);
    int a;
    int cnt;
    int flag = 0;
    vector<int>gatesv(g + 1, 0);
    for (int i = 1; i <= p; i++) {
        cin >> a;
        if (flag == 0){

            
        int t = a;
        if (gatesv[a] != 0)
            a = gatesv[a];
        while (gate[a] != 0 && a != 0) {
            a--;
        }
        if (a == 0)
        {
            flag = 1;
        }else
        cnt = i;
        gatesv[t] = a;
        gate[a] = i;

        }
    }


    cout << cnt << endl;





}



