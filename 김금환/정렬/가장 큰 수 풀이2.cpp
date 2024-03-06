#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> s_numbers;

// 두 문자열을 합쳐보고 더 큰 것이 앞에 오도록 함
bool compare(const string& s_num1, const string& s_num2) {
    return s_num1 + s_num2 > s_num2 + s_num1;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    // numbers 배열의 int들을 string으로 변환해서 s_numbers에 저장
    for (int number : numbers) {
        s_numbers.push_back(to_string(number));
    }
    
    // compare 함수를 이용하여 정렬
    sort(s_numbers.begin(), s_numbers.end(), compare);
    
    for (string s_number : s_numbers) {
        answer += s_number;
    }
    
    // s_number의 모든 원소가 0인 경우
    if (answer[0] == '0') answer = "0";
    
    return answer;
}