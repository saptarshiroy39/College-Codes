import random
import math


def dist(a, b):
    return math.hypot(a[0] - b[0], a[1] - b[1])


def total_distance(path, cities):
    return sum(
        dist(cities[path[i]], cities[path[i + 1]]) for i in range(len(path) - 1)
    ) + dist(cities[path[-1]], cities[path[0]])


def crossover(p1, p2):
    a, b = sorted(random.sample(range(len(p1)), 2))
    part = p1[a:b]
    return part + [c for c in p2 if c not in part]


def mutate(path, rate=0.01):
    for i in range(len(path)):
        if random.random() < rate:
            j = random.randint(0, len(path) - 1)
            path[i], path[j] = path[j], path[i]
    return path


def evolve(pop, cities):
    pop.sort(key=lambda p: total_distance(p, cities))
    next_gen = pop[:10]
    while len(next_gen) < len(pop):
        p1, p2 = random.choices(pop[:20], k=2)
        child = mutate(crossover(p1, p2))
        next_gen.append(child)
    return next_gen


def tsp_ga(cities, gen=200, size=50):
    pop = [random.sample(range(len(cities)), len(cities)) for _ in range(size)]
    for _ in range(gen):
        pop = evolve(pop, cities)
    best = min(pop, key=lambda p: total_distance(p, cities))
    return best, total_distance(best, cities)


# Main
if __name__ == "__main__":
    n = int(input("Enter number of cities: "))
    cities = [tuple(map(int, input().split())) for _ in range(n)]
    path, d = tsp_ga(cities)
    print("Best Path:", path)
    print("Distance:", round(d, 2))