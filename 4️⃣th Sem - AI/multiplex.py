from collections import deque, defaultdict

distances = set(map(int, input("Enter distances of multiplexes from residence : ").split()))

action_multiplexes = set(map(int, input("Enter multiplexes playing action movies: ").split()))

parking_availability = defaultdict(bool)
for multiplex in action_multiplexes:
    parking_status = (input(f"Parking availablity at multiplex {multiplex}? (y/n): ").strip().lower())
    parking_availability[multiplex] = parking_status == "y"


def bfs():
    queue = deque(sorted(distances))

    while queue:
        multiplex = queue.popleft()

        if multiplex in action_multiplexes and parking_availability[multiplex]:
            print(f"Selected Multiplex at {multiplex} km")
            return

    print("No suitable multiplex found")


bfs()
