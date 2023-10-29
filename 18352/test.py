from collections import deque

Q = deque()
G = [[] for i in range(300010)]

res = []

N, M, K, X = map(int, input().split())
for i in range(M):
    a, b = map(int, input().split())
    G[a].append(b)

flag = False

Q.append(X)

dist = [-1] * 300010
dist[X] = 0

while Q:
    temp = Q.popleft()
    for i in G[temp]:
        if dist[i] == -1:
            dist[i] = dist[temp] + 1
            Q.append(i)

for i in range(1, N+1):
    if dist[i] == K:
        flag = True
        print(i)

if flag == False:
    print(-1)