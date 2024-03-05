def solution(arr):
    answer = []
    answer.append(arr[0])
    idx = 0
    for i in range(1,len(arr)):
        if arr[idx] != arr[i]:
            idx = i
            answer.append(arr[i])
    return answer