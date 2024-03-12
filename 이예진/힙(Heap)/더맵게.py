import heapq
def solution(scoville, K):
    answer = 0
    # 힙큐 만들기
    heapq.heapify(scoville)
    
    while True:
        # 길이 작으면 런타임에러 뜰까봐
        if len(scoville) < 2:
            break
            
        # 가장 작은 거
        min1 = heapq.heappop(scoville)
        # 근데 가장 작은 게 K보다 크면 나가
        if min1 >= K:
            break
        # 아니라면 두 번째로 작은 거 pop해서 더하고 곱해야함
        else:
            min2 = heapq.heappop(scoville)
            heapq.heappush(scoville, min1 + min2 * 2)
            answer += 1
    # 스코빌의 0번 째가 K보다 크면 정답
    if scoville[0] >= K:
        return answer
    # 아니면 나가
    else:
        return -1
    
    
    
