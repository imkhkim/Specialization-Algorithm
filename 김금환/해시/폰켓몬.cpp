#include <vector>
#include <set>

using namespace std;

set<int> types;

int solution(vector<int> nums)
{
    // 종류 수 세기
    for (int num : nums) {
        types.insert(num);
    }
    
    // 종류 수가 선택할 수 있는 폰켓몬의 수보다 크거나 같으면 선택할 수 있는 폰켓몬의 수가 답
    // 종류 수가 선택할 수 있는 폰켓몬의 수보다 작으면 종류 수가 답
    int answer = types.size() >= nums.size() / 2 ? nums.size() / 2 : types.size();
    return answer;
}