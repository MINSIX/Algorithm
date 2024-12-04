#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> arr;
    for(int i=0;i<nums.size();i++){
        arr.insert(nums[i]);
    }
    
    if(arr.size()>nums.size()/2)
        return nums.size()/2;
    else
        return arr.size();
    
    
    
}