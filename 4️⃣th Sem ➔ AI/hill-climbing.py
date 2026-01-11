import numpy as np
import matplotlib.pyplot as plt


def hill_climbing(
    f, x0, initial_step_size=0.1, min_step_size=0.0001, max_iterations=1000):

    x = x0
    step_size = initial_step_size
    iterations = 0
    path = [x]

    while iterations < max_iterations and step_size >= min_step_size:
        current_value = f(x)
        left_value = f(x - step_size)
        right_value = f(x + step_size)

        if left_value > current_value and left_value >= right_value:
            x = x - step_size
            path.append(x)
        elif right_value > current_value:
            x = x + step_size
            path.append(x)
        else:
            step_size /= 2

        iterations += 1

        if iterations % 100 == 0:
            print(f"Iteration {iterations}, x = {x}, f(x) = {f(x)}, step_size = {step_size}")

    return x, path


if __name__ == "__main__":

    expr = input("Enter the function in terms of x (-x**2 + 5 or x**2 - 4*x + 4): ")
    f = lambda x: eval(expr, {"x": x, "np": np})

    try:
        x0 = float(input("Enter initial value of x: "))
    except ValueError:
        print("Invalid input. Using default value of 0.")
        x0 = 0

    result, path = hill_climbing(f, x0)

    print("\nResults:")
    print(f"Local maximum found at x = {round(result, 6)}")
    print(f"Maximum value = {round(f(result), 6)}")
    print(f"Algorithm took {len(path)} steps")

    try:
        padding = max(5, (max(path) - min(path)) * 0.5)
        x_min = min(path) - padding
        x_max = max(path) + padding

        x_values = np.linspace(x_min, x_max, 500)
        y_values = [f(x) for x in x_values]

        plt.figure(figsize=(10, 6))

        plt.plot(x_values, y_values, "b-", label=f"Function: {expr}")

        path_y = [f(x) for x in path]
        plt.plot(path, path_y, "r-", alpha=0.5, label="Search path")
        plt.scatter(path, path_y, color="red", marker="o", s=30, alpha=0.7)

        plt.scatter(
            [path[0]],
            [f(path[0])],
            color="green",
            marker="o",
            s=100,
            label="Start point",
        )
        plt.scatter(
            [result],
            [f(result)],
            color="purple",
            marker="*",
            s=200,
            label="Found maximum",
        )

        plt.xlabel("x")
        plt.ylabel("f(x)")
        plt.title("Hill Climbing Algorithm Visualization")
        plt.legend()
        plt.grid(True)

        plt.show()
    except Exception as e:
        print(f"Couldn't create visualization: {e}")
