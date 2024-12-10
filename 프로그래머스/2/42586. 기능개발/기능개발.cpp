#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int now=0;
    for(int i=0;i<progresses.size();i++){
        answer.push_back((100 - progresses[i] + speeds[i] - 1) / speeds[i]);
    }
    vector<int> pp;
    pp.push_back(1);
    int index=0;
    for(int i=1;i<progresses.size();i++){
    if(answer[now]>=answer[i]){
        pp[index]++;
    }
    else{
        now=i;
        index++;
        pp.push_back(1);
        
    }
}
    return pp;
}