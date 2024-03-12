#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxOfMin = 0;
    int maxOfAll = 0;
    
    for (vector<int> size : sizes) {
        // 한 명함의 w, h 중 작은 값을 구하고, 이 값들 중에서 최댓값 구하기
        maxOfMin = max(maxOfMin, min(size[0], size[1]));
        // 모든 명함의 w, h 중에서 최댓값 구하기
        maxOfAll = max(maxOfAll, max(size[0], size[1]));
    }
    
    return maxOfMin * maxOfAll;
}