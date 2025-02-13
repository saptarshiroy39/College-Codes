from collections import deque, defaultdict

graph = defaultdict(list)
for _ in range(int(input("Number of Edges: "))):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

def bfs(start):
    visited, queue = set(), deque([start])
    while queue:
        node = queue.popleft()
        if node not in visited:
            print(node, end=' ')
            visited.add(node)
            queue.extend(graph[node])

bfs(int(input("Starting Point: ")))
