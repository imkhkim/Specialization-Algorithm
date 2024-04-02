def find(a):
    global par
    if par[a] != a:
        par[a] = find(par[a])
    return par[a]

def union(a,b):
    global par
    a = find(a)
    b = find(b)
    if a < b:
        par[b] = a
    else:
        par[a] = b


def solution(n, computers):
    global par
    par = [i for i in range(n)]
    l = []
    for i in range(n):
        for j in range(n):
            if computers[i][j] == 1:
                if i != j:
                    union(i,j)
    s = set()
    for i in par:
        s.add(find(par[i]))
    return len(s)
