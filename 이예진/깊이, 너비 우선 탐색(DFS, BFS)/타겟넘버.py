def r(numbers, idx, total, target):
    global answer
    if idx == len(numbers):
        if total == target:
            answer += 1
        return
    r(numbers,idx+1, total+numbers[idx],target)
    r(numbers,idx+1, total-numbers[idx],target)
    

def solution(numbers, target):
    global answer
    answer = 0
    r(numbers,0,0,target)
    return answer
