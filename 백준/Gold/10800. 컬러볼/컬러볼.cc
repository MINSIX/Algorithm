#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int n;
bool cmp(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
	if (a.first.first == b.first.first)return a.first.second < b.first.second;
	return a.first.first < b.first.first;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	int a, b;

	vector<pair<pair<int, int>,int>>balls;
	vector<int>sum(n);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		balls.push_back({ {b,a},i });
	}
	sort(balls.begin(), balls.end(),cmp);
	unordered_map<int, int> color2size;
	int total = 0;
	int lastsize = 0;
	int lastsum = 0;
	int lastcolor = 0;
	int times = 1;
	for (auto& it : balls) {
		
		if (it.first.first == lastsize) {
		
			if (it.first.second == lastcolor){ 
				sum[it.second] += lastsum +it.first.first*times - color2size[it.first.second];
				times++;

			}
			else
			{
				times =1;
				sum[it.second] += lastsum - color2size[it.first.second];
			}

			
		}
		else
		{
			times = 1;
			sum[it.second] += total - color2size[it.first.second];
			lastsize=it.first.first;
			lastsum = total;
			
		}
		lastcolor = it.first.second;
		total += it.first.first;
		color2size[it.first.second] += it.first.first;
		
	}

	for (auto& a : sum) cout << a << "\n";


}
