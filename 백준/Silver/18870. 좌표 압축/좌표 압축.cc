#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int N, M;
int comparesig[1000001]={0,};
bool compare(const pair<int, int>& a,const pair<int, int>& b)
{
   
    return a.second < b.second; // first 값이 같지 않다면 더 큰 값이 뒤로 가게 해라!
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<pair<int,int>> arr;
    vector<pair<int,int>> arr1;

    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        arr.push_back(make_pair(i, a));
     
    }
    sort(arr.begin(), arr.end(),compare);
    int now = -1;
    for (int i = 0; i < N; i++)
    {
        if(i!=0&&arr[i].second==arr[i-1].second){
            
            arr1.push_back(make_pair(now, arr[i].first));
        
        }
        else {
            now++;
            arr1.push_back(make_pair(now, arr[i].first));
 
           
        
        }
    }
    sort(arr1.begin(), arr1.end(),compare);
    for (int i = 0; i < N; i++) {
        cout << arr1[i].first << " ";
    
    }

    return 0;
}