#include <string>
#include <vector>
#include <queue>

using namespace std;

deque<int> DQ; // 단조감소 deque

string solution(string number, int k) {
    string answer = "";
    
    int cntErase = 0;
    for (int i = 0; i < number.size(); ++i) {
        while (!DQ.empty() && DQ.back() < number[i]) {
            // 새로 들어온 숫자 앞쪽에 있는 작은 숫자들 가까운 것 부터 제거
            DQ.pop_back();
            ++cntErase;
            
            // k개 만큼 제거했으면 나머지 DQ에 담고 종료
            if (cntErase == k) {
                for (int j = i; j < number.size(); ++j)
                    DQ.push_back(number[j]);
                break;
            }
        }
        
        if (cntErase == k) break;
        
        DQ.push_back(number[i]);
    }
    
    // 단조감소 DQ를 만들었는데 k개만큼 제거하지 못한 경우
    while (cntErase++ < k) {
        // DQ의 맨 뒤에서부터 하나씩 제거
        DQ.pop_back();
    }
    
    for (char num : DQ) {
        answer += num;
    }
    
    return answer;
}