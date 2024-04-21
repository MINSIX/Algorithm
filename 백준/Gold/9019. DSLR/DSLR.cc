#include<bits/stdc++.h>
using namespace std;
int T;

int D(int a) {


	return a * 2 % 10000;


}
int S(int a) {

	if (a > 0)
		return a - 1;
	else
		return 9999;



}
int L(int a) {


	int d1 = a / 1000;
	a -= d1*1000;
	int d2 = a / 100;
	a -= d2*100;
	int d3 = a / 10;
	a -= d3*10;
	int d4 = a / 1;
	a -= d4;

	return d4 * 10 + d1 + d2 * 1000 + d3*100;

}
int R(int a) {

	int d1 = a / 1000;
	a -= d1*1000;
	int d2 = a / 100;
	a -= d2*100;
	int d3 = a / 10;
	a -= d3*10;
	int d4 = a / 1;
	a -= d4;

	return d4 * 1000 + d1 * 100 + d2 * 10 + d3;



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> T;
	while (T-- > 0){
		int a, b;
		cin >> a >> b;
		queue<pair<int,string>> q;
	vector<bool>visited(10000, false);
        visited[a]=true;
		q.push({ a,"" });
		while (!q.empty()) {
			int now = q.front().first;
			string s = q.front().second;
			q.pop();
			
			if (now == b) {
				cout << s << '\n';
				
				break;
			}
			else {
				int a = L(now);
				if(!visited[a]){
				q.push({a,s + "L" });
				visited[a] = true;
				
				}
		        
				a = D(now);
				if (!visited[a]) {
					q.push({ a,s + "D" });
					visited[a] = true;

				}
				a = S(now);
				if (!visited[a]) {
					q.push({ a,s + "S" });
					visited[a] = true;

				}
				a = R(now);
				if (!visited[a]) {
					q.push({ a,s + "R" });
					visited[a] = true;

				}
		
			
		
	
			}




		}





	}

}