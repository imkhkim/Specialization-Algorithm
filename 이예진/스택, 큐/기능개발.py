import math
def solution(progresses, speeds):
    answer = []
    l = []
    # 며칠 간 작업을 해야하는지
    for i in range(len(progresses)):
        l.append(math.ceil((100-progresses[i])/speeds[i]))
    # tmp는 배포 개수에 대한 누적 변수, idx는 최근 것 중 가장 큰 작업일이 필요한 작업의 인덱스
    tmp = 1
    idx = 0
    for i in range(1,len(l)):
        # 최근 것 중에 큰 작업일이 필요하다면 이것도 같이 배포 가능
        if l[idx] >= l[i]:
            tmp+=1
        # 아니라면 그에 맞추어 초기화
        else:
            idx = i
            answer.append(tmp)
            tmp = 1
    # 마지막 배포 반영
    answer.append(tmp)        
    return answer