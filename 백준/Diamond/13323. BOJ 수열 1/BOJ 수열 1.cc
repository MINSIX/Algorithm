#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int now, pre;
    long long sum = 0;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        cin >> now;
        now -= i;
        pq.push(now);

        if (i > 0) {  
            if (pq.top() > now) {
                sum += pq.top() - now;
                pq.pop();
                pq.push(now);
            }
        }
    }

    cout << sum << endl;
    return 0;
}