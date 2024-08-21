#include<bits/stdc++.h>
using namespace std;

vector<int>arr;
void post(int start, int end){
	if(start>=end) return;
	int i=0;
	for(i=start+1;i<end;i++)
		if(arr[start]<arr[i]) break;
	
	post(start+1,i);
	post(i,end);
	cout << arr[start]<<"\n";
	
	return;
}
int main(){


int a;
while(cin >> a){
  arr.push_back(a);
}
  post(0,arr.size());
  
}