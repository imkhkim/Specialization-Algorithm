def solution(answers):
    answer = []
    l1 = [1,2,3,4,5]
    l2 = [2,1,2,3,2,4,2,5]
    l3 = [3,3,1,1,2,2,4,4,5,5]
    
    cnt1 = 0
    cnt2 = 0
    cnt3 = 0
    # l1,l2,l3을 무한반복하는 거보단 나머지로 자름
    for i in range(len(answers)):
        if l1[i%len(l1)] == answers[i]:
            cnt1 += 1
        if l2[i%len(l2)] == answers[i]:
            cnt2 += 1
        if l3[i%len(l3)] == answers[i]:
            cnt3 += 1
    
    l = [cnt1,cnt2,cnt3]
    for i in range(3):
        if l[i] == max(l):
            answer.append(i+1)

    
    return answer