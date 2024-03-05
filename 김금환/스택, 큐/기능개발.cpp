#include <vector>
#include <cmath>

using namespace std;

vector<int> workingDay;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for (int i = 0; i < progresses.size(); ++i) {
        workingDay.push_back(ceil(((double)100 - progresses[i]) / speeds[i]));
    }
        
    int cnt = 1;
    int day = workingDay[0];
    for (int i = 0; i < workingDay.size() - 1; ++i) {
        if (day >= workingDay[i + 1]) {
            ++cnt;
        } else {
            answer.push_back(cnt);
            cnt = 1;
            day = workingDay[i + 1];
        }
    }
    
    answer.push_back(cnt);
    
    return answer;
}