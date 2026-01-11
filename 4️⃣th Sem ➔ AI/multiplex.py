from collections import deque, defaultdict

multiplexes = list(map(int, input("Enter distances of multiplexes from residence: ").split()))
action_multiplexes = set(map(int, input("Enter multiplexes playing action movies: ").split()))
parking_available_multiplexes = set(map(int, input("Enter multiplexes with parking available: ").split()))

graph = defaultdict(list)

for m in multiplexes:
    graph[0].append(m)
    graph[m].append(0)

def bfs(start):
    visited, queue = set(), deque([start])

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)

            if node != 0 and node in action_multiplexes and node in parking_available_multiplexes:
                print(f"🎬 Best multiplex found at {node} km!")
                return

            queue.extend(set(graph[node]) - visited)

    print("😔 No suitable multiplex found.")

bfs(0)