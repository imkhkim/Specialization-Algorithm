import math
import itertools
def solution(numbers):
    answer = 0
    l = []
    s = set()
    
    # 순열을 통해서 모든 경우 구하기
    for i in range(1,len(numbers)+1):
        a = list(itertools.permutations(numbers,i))
        l.append(a)
    # 겹치지 않는 순수한 정수 구하기
    for i in l:
        for j in i:
            tmp = ""
            for k in j:
                tmp += k
            s.add(int(tmp))
    # 소수 개수
    for i in s:
        if is_prime(i):
            answer += 1
            
    return answer
# 소수판별
def is_prime(n):
    if n < 2:
        return False
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True