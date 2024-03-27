from collections import deque
def solution(maps):
    answer = 0
    
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    
    q = deque()
    q.append([0,0])
    xn = len(maps)
    yn = len(maps[0])
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < xn and 0 <= ny < yn and maps[nx][ny] == 1:
                maps[nx][ny] = maps[x][y]+ 1
                q.append([nx,ny])
                
    if maps[xn-1][yn-1] != 1:
        return maps[xn-1][yn-1]
    else:
        return -1
