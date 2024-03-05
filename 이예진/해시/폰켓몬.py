# 방법 1 set 사용
def solution(nums):
    n = len(nums)//2
    nums_s= len(set(nums))
    if n < nums_s:
        return n
    return nums_s

# 방법 2 dictionary 사용
def solution(nums):
    answer = 0
    d = {}
    
    n = len(nums)//2
    
    for i in nums:
        if i not in d:
            d[i] = 1
        else:
            d[i] += 1
    
    if len(d) >= n:
        answer = n
    else:
        answer = len(d)
        
    return answer