#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N; 

    vector<int> ss(N);
    for (int i = 0; i < N; i++) {
        cin >> ss[i];
    }

    unordered_map<int, int> freq;
    int left = 0;
    int svmax = 0;

    for (int right = 0; right < N; right++) {
       freq[ss[right]]++;

       
        int unique_count = freq.size();
        while (unique_count > 2) {
         
            freq[ss[left]]--;
            if (freq[ss[left]] == 0) {
                freq.erase(ss[left]);
            }
            left++;
            unique_count = freq.size();
        }

        svmax = max(svmax, right - left+1);
    }

    cout << svmax << endl;

    return 0;
}
