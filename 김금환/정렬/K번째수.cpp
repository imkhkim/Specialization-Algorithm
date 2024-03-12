#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int> command : commands) {
        // 배열 자르기
        vector<int> cutArray;
        for (int i = command[0] - 1; i < command[1]; ++i) {
            cutArray.push_back(array[i]);
        }
        
        // 정렬
        sort(cutArray.begin(), cutArray.end());
        
        answer.push_back(cutArray[command[2] - 1]);
    }
    
    return answer;
}