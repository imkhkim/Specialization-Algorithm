#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> prefix;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for (string phone_number : phone_book) {
        for (int i = 1; i < phone_number.size(); ++i) {
            prefix.insert(phone_number.substr(0, i));
        }
    }

    for (string phone_number : phone_book) {
        if (prefix.find(phone_number) != prefix.end()) {
            answer = false;
            break;
        }
    }
    
    return answer;
}