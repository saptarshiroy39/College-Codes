import random


def take_input():
    n = int(input("Enter number of cities: "))
    print("Enter cost matrix row by row:")
    cost = [list(map(int, input().split())) for _ in range(n)]
    start = int(input(f"Enter starting city index (0 to {n-1}): "))
    return cost, start


def total_cost(tour, cost):
    return (sum(cost[tour[i]][tour[i + 1]] for i in range(len(tour) - 1)) + cost[tour[-1]][tour[0]])


def fitness(tour, cost):
    return 1 / total_cost(tour, cost)


def initial_population(size, n, start):
    pop = []
    nodes = list(range(n))
    nodes.remove(start)
    for _ in range(size):
        tour = [start] + random.sample(nodes, len(nodes))
        pop.append(tour)
    return pop


def crossover(p1, p2, start):
    p1, p2 = p1[1:], p2[1:]
    a, b = sorted(random.sample(range(len(p1)), 2))
    child = [None] * len(p1)
    child[a : b + 1] = p1[a : b + 1]
    pos = (b + 1) % len(p1)
    for c in p2:
        if c not in child:
            while child[pos] is not None:
                pos = (pos + 1) % len(p1)
            child[pos] = c
    return [start] + child


def mutate(tour, rate=0.02):
    if random.random() < rate:
        i, j = random.sample(range(1, len(tour)), 2)
        tour[i], tour[j]= tour[j], tour[i]
    return tour


def select(pop, cost):
    return max(random.sample(pop, 3), key=lambda x: fitness(x, cost))


def genetic_algo(cost, start, pop_size=100, gen=500):
    n = len(cost)
    pop = initial_population(pop_size, n, start)
    best = min(pop, key=lambda x: total_cost(x, cost))
    for _ in range(gen):
        pop.sort(key=lambda x: fitness(x, cost), reverse=True)
        if total_cost(pop[0], cost) < total_cost(best, cost):
            best = pop[0]
        new_pop = []
        for _ in range(pop_size // 2):
            p1, p2 = select(pop, cost), select(pop, cost)
            new_pop.extend([mutate(crossover(p1, p2, start)), mutate(crossover(p2, p1, start))])
        pop = new_pop
    return best + [start], total_cost(best, cost)


cost_matrix, start_city = take_input()
path, min_cost = genetic_algo(cost_matrix, start_city)
print("\nBest path:", path)
print("Minimum cost:", min_cost)
