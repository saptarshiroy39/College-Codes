from collections import defaultdict

graph = defaultdict(list)
for _ in range(int(input("Number of Edges: "))):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

def dfs(node, visited=set()):
    if node not in visited:
        print(node, end=" ")
        visited.add(node)
        for neighbor in graph[node]:
            dfs(neighbor, visited)

dfs(int(input("Starting Point: ")))
