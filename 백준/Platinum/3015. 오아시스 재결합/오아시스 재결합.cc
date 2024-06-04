#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    long long p;
    stack<pair<long long, long long>> pr;   //키 , 같은사람.

    long long cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> p;


        int now = 1;

        while (!pr.empty() && pr.top().first <= p) { //다음사람이 같거나 큰경우
            if (pr.top().first == p) {//다음사람이 같은경우 now ++;
                cnt += pr.top().second;
                now = pr.top().second + 1;
                pr.pop();
            }
            else {      //다음사람이 큰경우 now 초기화
                cnt += pr.top().second;
                pr.pop();
                now = 1;

            }
          
        }
        if (!pr.empty()) //앞사람만 보는 경우
            cnt++;
        pr.push({ p,now });
    }
    cout << cnt << endl;

    return 0;
}