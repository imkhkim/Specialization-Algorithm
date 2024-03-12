def solution(array, commands):
    answer = []
    for i,j,k in commands:
        tmp_list = []
        for tmp in range(i - 1, j):
            tmp_list.append(array[tmp])
        tmp_list.sort()
        answer.append(tmp_list[k - 1])
    return answer