#include<bits/stdc++.h>

using namespace std;
long long n, m, k;
vector<pair<int, int>> jually;

bool compare(const pair<int,int>& a, const pair<int,int>& b) {

    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n>> k;
    long long m, v;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        jually.push_back(make_pair(m, v));
    }
    vector<int>bag;
    long long a;
    for (int i = 0; i < k; i++) {
        cin >> a;
        bag.push_back(a);
        
    }
    priority_queue<long long> pq;
   sort(bag.begin(), bag.end());
    sort(jually.begin(), jually.end(), compare);
    long long sum = 0;

    int now = 0;

    for (int i = 0; i < k; i++) {
        if(now<n)
        while (jually[now].first <= bag[i] && now < n) {
            pq.push(jually[now].second);



            now++;
            if (now >= n){

                break;
            }
        }
        if(!pq.empty()){
        sum += pq.top();

        pq.pop();

        }

    }

    cout << sum;
 
}