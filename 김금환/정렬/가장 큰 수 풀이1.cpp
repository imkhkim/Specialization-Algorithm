#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int& num1, const int& num2) {
    // 비교함수 안에서 문자열로 변환한 것끼리 비교
    string n1 = to_string(num1);
    string n2 = to_string(num2);
    
    // 맨 앞자리 수 부터 비교
    int i = 0, j = 0;
    while (true) {
        if (n1[i] - '0' > n2[j] - '0')
            return true; // 바꾸지 않아야 하는 경우
        else if (n1[i] - '0' < n2[j] - '0')
            return false; // 바꿔야 하는 경우
        else {
            if (i == n1.size() - 1 && j == n2.size() - 1)
                return false; // 두 수의 우선순위가 같은 경우
            
            // 비교하다가 맨 끝 자리까지 확인한 경우 다시 맨 앞 자리로 돌아가서 계속 비교
            if (++i == n1.size())
                i = 0;
            if (++j == n2.size())
                j = 0;
        }
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), compare);
    
    for (int number : numbers) {
        answer += to_string(number);
    }
    
    // numbers의 모든 원소가 0인 경우
    if (answer[0] == '0') answer = "0";
    
    return answer;
}