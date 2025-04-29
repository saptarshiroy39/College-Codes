import numpy as np
import matplotlib.pyplot as plt


def generate_neighbours(x, step_size=1):
    return [x - step_size, x + step_size]


def hill_climbing(f, x0, max_iterations=1000):
    x = x0
    iterations = 0
    path = [x]
    while iterations < max_iterations:
        neighbours = generate_neighbours(x)
        best_neighbour = max(neighbours, key=f)
        if f(best_neighbour) <= f(x):
            return x, path
        x = best_neighbour
        path.append(x)
        iterations += 1
    return x, path


if __name__ == "__main__":
    expr = input("Enter the function in terms of x (x**2 - 4*x + 4): ")
    f = lambda x: eval(expr, {"x": x})
    x0 = int(input("Enter initial value: "))

    result, path = hill_climbing(f, x0)
    print("Local maximum found at x =", result)

    x_values = np.linspace(min(path) - 10, max(path) + 10, 400)
    y_values = [f(x) for x in x_values]

    plt.plot(x_values, y_values, label=f"Function: {expr}")
    plt.scatter(path, [f(x) for x in path], color="red", marker="o", label="Hill Climbing Path")
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.title("Hill Climbing Algorithm Visualization")
    plt.legend()
    plt.grid()
    plt.show()
