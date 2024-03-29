#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    if (arr.size() > 0)
        answer.push_back(arr[0]);
    
    for (int num : arr) {
        if (answer.back() != num)
            answer.push_back(num);
    }
    
    return answer;
}