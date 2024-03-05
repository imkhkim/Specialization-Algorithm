#include <string>
#include <vector>
#include <set>

using namespace std;

multiset<string> ms;

string solution(vector<string> participant, vector<string> completion) {
    // 완주자 명단 만들기
    for (string c : completion) {
        ms.insert(c);
    }

    string answer;
    
    for (string p : participant) {
        auto iter = ms.find(p);
        if (iter != ms.end()) {
            // 참가자가 완주자 명단에 있으면 해당 참가자를 완주자 명단에서 지우고 다음 참가자 확인
            ms.erase(iter);
        } else {
            // 참가자가 완주자 명단에 없으면 완주하지 못한 참가자이므로 정답
            answer = p;
            break;
        }
    }
    
    return answer;
}