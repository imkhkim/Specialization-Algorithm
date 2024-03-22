#include <string>
#include <vector>

using namespace std;

// 전체 학생의 체육복 개수
int cnt[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // 기본 체육복 개수는 1
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 1;
    }
    
    // 도난으로 체육복 개수 -1
    for (int i = 0; i < lost.size(); ++i) {
        --cnt[lost[i]];
    }
    
    // 여벌로 체육복 개수 +1
    for (int i = 0; i < reserve.size(); ++i) {
        ++cnt[reserve[i]];
    }
    
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) { // 체육복이 없는 사람
            if (i - 1 >= 0 && cnt[i - 1] == 2) { // 앞에서 빌림
                ++answer;
            } else if (i + 1 <= n && cnt[i + 1] == 2) { // 뒤에서 빌림
                ++answer;
                --cnt[i + 1];
            }
        } else // 체육복이 있는 사람
            ++answer;
    }
    
    return answer;
}