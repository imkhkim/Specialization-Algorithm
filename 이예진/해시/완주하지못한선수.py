def solution(participant, completion):
    d = {}
    for i in participant:
        if i in d.keys():
            d[i] += 1
        else:
            d[i] = 1
    
    for i in completion:
        if i in d.keys():
            d[i] -= 1
    
    for i,j in d.items():
        if j == 1:
            return i
            