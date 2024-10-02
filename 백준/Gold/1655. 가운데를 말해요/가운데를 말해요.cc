#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    int a;
    
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    for(int i = 0; i < N; i++){
        cin >> a;
        if (maxHeap.empty() || a <= maxHeap.top()) {
            maxHeap.push(a);
        } else {
            minHeap.push(a);
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        cout << maxHeap.top() << "\n";
    }

    return 0;
}
