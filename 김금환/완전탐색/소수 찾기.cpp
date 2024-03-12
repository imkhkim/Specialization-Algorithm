#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int number[7];
bool selected[7];
int numSize, newNumberSize, answer;
set<int> setNumbers;

bool isPrime(int num) {
    if (num <= 1)
        return false;
    
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void comb(int cnt) {
    if (cnt == numSize) {
        // 만들어진 조합으로 숫자 만들기
        int newNumber[7];
        newNumberSize = 0;
        for (int i = 0; i < numSize; ++i) {
            if (selected[i]) {
                newNumber[newNumberSize++] = number[i];
            }
        }
        
        // 숫자의 자리를 바꿔가며 set에 넣기
        do {
            int num = 0;
            for (int i = 0; i < newNumberSize; ++i) {
                num = num * 10 + newNumber[i];
            }
            
            setNumbers.insert(num);
        } while (next_permutation(newNumber, newNumber + newNumberSize));
        
        return;
    }
    
    // 가능한 수 조합 만들기
    selected[cnt] = true;
    comb(cnt + 1);
    selected[cnt] = false;
    comb(cnt + 1);
}

int solution(string numbers) {
    numSize = numbers.size();
    for (int i = 0; i < numSize; ++i) {
        number[i] = numbers[i] - '0';
    }
    
    sort(number, number + numSize);
    
    comb(0);
    
    // set에서 하나씩 꺼내면서 소수 판별
    for (int num : setNumbers) {
        if (isPrime(num)) {
            ++answer;
        }
    }
    
    return answer;
}