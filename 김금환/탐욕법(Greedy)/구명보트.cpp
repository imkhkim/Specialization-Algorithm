#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
        
    sort(people.begin(), people.end());
    
    int front = 0;
    int rear = people.size() - 1;
    while (front <= rear) {
        if (people[front] + people[rear] > limit) {
            // 두 사람(동일한 몸무게인 두 사람 포함)의 몸무게 합이 limit를 초과하면
            // 더 무거운 사람을 보트에 태운다.
            --rear;
        } else {
            // 두 사람(동일한 몸무게인 두 사람 포함)의 몸무게 합이 limit 이하이면
            // 두 사람 다 보트에 태운다.
            ++front;
            --rear;
        }
        
        ++answer;
    }
    
    return answer;
}