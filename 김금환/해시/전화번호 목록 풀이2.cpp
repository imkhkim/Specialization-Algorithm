#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> phone_numbers;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for (string phone_number : phone_book) {
        phone_numbers.insert(phone_number);
    }
    
    for (string phone_number : phone_book) {
        
        // for문을 돌면서
        for (int i = 1; i < phone_number.size(); ++i) {
            
            // 현재 번호의 접두어들 중 다른 번호와 일치하는 것이 있으면 종료
            if (phone_numbers.find(phone_number.substr(0, i)) != phone_numbers.end()) {
                answer = false;
                break;
            }
        }
    }

    return answer;
}