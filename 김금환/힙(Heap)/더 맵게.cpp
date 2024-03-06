#include <string>
#include <vector>
#include <queue>

using namespace std;

// 최소 힙
priority_queue<int, vector<int>, greater<int>> foods;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for (int food : scoville) {
        foods.push(food);
    }
    
    // 모든 음식의 스코빌 지수가 아직 K 이상이 아닌 동안
    while (foods.top() < K) {
        
        // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우
        if (foods.size() < 2) {
            answer = -1;
            break;
        }
        
        // 음식 섞기
        int food1 = foods.top();
        foods.pop();
        int food2 = foods.top();
        foods.pop();
        foods.push(food1 + food2 * 2);
        
        ++answer;
    }
    
    return answer;
}