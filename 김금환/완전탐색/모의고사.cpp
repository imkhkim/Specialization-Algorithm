#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    int maxCnt = 0;
    
    for (int i = 0; i < answers.size(); ++i) {
        // 1번 수포자 확인
        if (answers[i] == ((i % 5) + 1)) {
            ++cnt1;
        }
        
        // 2번 수포자 확인
        if (answers[i] == 2 && (i % 2 == 0)) {
            ++cnt2;
        } else if (answers[i] == 1 && (i % 8) == 1) {
            ++cnt2;
        } else if (answers[i] == 3 && (i % 8) == 3) {
            ++cnt2;
        } else if (answers[i] == 4 && (i % 8) == 5) {
            ++cnt2;
        } else if (answers[i] == 5 && (i % 8) == 7) {
            ++cnt2;
        }
        
        // 3번 수포자 확인
        if (answers[i] == 3 && (i % 10 == 0 || i % 10 == 1)) {
            ++cnt3;
        } else if (answers[i] == 1 && (i % 10 == 2 || i % 10 == 3)) {
            ++cnt3;
        } else if (answers[i] == 2 && (i % 10 == 4 || i % 10 == 5)) {
            ++cnt3;
        } else if (answers[i] == 4 && (i % 10 == 6 || i % 10 == 7)) {
            ++cnt3;
        } else if (answers[i] == 5 && (i % 10 == 8 || i % 10 == 9)) {
            ++cnt3;
        }
        
        maxCnt = max({cnt1, cnt2, cnt3});
    }
    
    vector<int> answer;
    if (cnt1 == maxCnt) answer.push_back(1);
    if (cnt2 == maxCnt) answer.push_back(2);
    if (cnt3 == maxCnt) answer.push_back(3);
    return answer;
}