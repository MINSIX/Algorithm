#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int, int>> check; 
    map<string, int> sumsum;     

    for (int i = 0; i < plays.size(); i++) {
        check.push_back({plays[i], i});
        sumsum[genres[i]] += plays[i];
    }

    vector<pair<string, int>> pp(sumsum.begin(), sumsum.end());
    sort(pp.begin(), pp.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second > b.second; 
    });

    map<string, int> priori; 
    int now = 1;
    for (int i = 0; i < pp.size(); i++) {
        priori[pp[i].first] = now++;
    }

    sort(check.begin(), check.end(), [&](pair<int, int> a, pair<int, int> b) {
        int genre_a_priority = priori[genres[a.second]];
        int genre_b_priority = priori[genres[b.second]];

        if (genre_a_priority != genre_b_priority) {
            return genre_a_priority < genre_b_priority; 
        }
        return a.first > b.first; 
    });

    map<string, int> m;
    for (int i = 0; i < check.size(); i++) {
        if (m[genres[check[i].second]] == 2) 
            continue;

        answer.push_back(check[i].second);
        m[genres[check[i].second]]++;
    }

    return answer;
}
