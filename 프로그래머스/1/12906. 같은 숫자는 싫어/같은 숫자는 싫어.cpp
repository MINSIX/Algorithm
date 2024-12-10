#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    auto it= unique(arr.begin(),arr.end());
    arr.erase(it,arr.end());
    return arr;
}