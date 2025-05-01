from collections import defaultdict

graph = defaultdict(list)

for _ in range(int(input("Number of Edges: "))):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)


def dfs(start):
    visited, stack = set(), [start]

    while stack:
        node = stack.pop()
        if node not in visited:
            print(node, end=" ")
            visited.add(node)
            stack.extend(reversed(graph[node]))


start = int(input("Starting Point: "))
print("DFS Traversal: ", end="")
dfs(start)
