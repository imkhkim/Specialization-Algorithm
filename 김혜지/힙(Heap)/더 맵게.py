import heapq
def solution(scoville, K):
    answer = 0
    # 스코빌 지수 최소힙으로 만들기
    heapq.heapify(scoville)
    
    # 모든 스코빌 지수가 k 미만인 경우만 수행
    while scoville[0] < K:
        # 스코빌 길이가 2 이하일 때 섞을 수 없음
        if len(scoville) < 2:
            return -1
        else:
            first = heapq.heappop(scoville)
            second = heapq.heappop(scoville)
            tmp = first + (second * 2)
            heapq.heappush(scoville,tmp)
            answer += 1
    return answer
        