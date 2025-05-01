
equation = input("Enter the equation in terms of x (x**2 - 4*x + 4): ")
initial_x = float(input("Enter the initial value of x: "))

def objective_function(x):
    return eval(equation)

def hill_climb(x):
    step_size = 0.01
    max_iterations = 1000

    for _ in range(max_iterations):
        left = x - step_size
        right = x + step_size

        if objective_function(left) > objective_function(x):
            x = left
        elif objective_function(right) > objective_function(x):
            x = right
        else:
            break

    return x, objective_function(x)

best_x, best_value = hill_climb(initial_x)
print("Local maximum at x =", round(best_x, 4))
print("Maximum value =", round(best_value, 4))


# import numpy as np
# import matplotlib.pyplot as plt


# def generate_neighbours(x, step_size=1):
#     return [x - step_size, x + step_size]


# def hill_climbing(f, x0, max_iterations=1000):
#     x = x0
#     iterations = 0
#     path = [x]
#     while iterations < max_iterations:
#         neighbours = generate_neighbours(x)
#         best_neighbour = max(neighbours, key=f)
#         if f(best_neighbour) <= f(x):
#             return x, path
#         x = best_neighbour
#         path.append(x)
#         iterations += 1
#     return x, path


# if __name__ == "__main__":
#     expr = input("Enter the function in terms of x (x**2 - 4*x + 4): ")
#     f = lambda x: eval(expr, {"x": x})
#     x0 = int(input("Enter initial value: "))

#     result, path = hill_climbing(f, x0)
#     print("Local maximum found at x =", result)

#     x_values = np.linspace(min(path) - 10, max(path) + 10, 400)
#     y_values = [f(x) for x in x_values]

#     plt.plot(x_values, y_values, label=f"Function: {expr}")
#     plt.scatter(
#         path, [f(x) for x in path], color="red", marker="o", label="Hill Climbing Path"
#     )
#     plt.xlabel("x")
#     plt.ylabel("f(x)")
#     plt.title("Hill Climbing Algorithm Visualization")
#     plt.legend()
#     plt.grid()
#     plt.show()


# import numpy as np
# import matplotlib.pyplot as plt


# def hill_climbing(
#     f, x0, initial_step_size=0.1, min_step_size=0.0001, max_iterations=1000
# ):

#     x = x0
#     step_size = initial_step_size
#     iterations = 0
#     path = [x]

#     while iterations < max_iterations and step_size >= min_step_size:
#         current_value = f(x)
#         left_value = f(x - step_size)
#         right_value = f(x + step_size)

#         if left_value > current_value and left_value >= right_value:
#             x = x - step_size
#             path.append(x)
#         elif right_value > current_value:
#             x = x + step_size
#             path.append(x)
#         else:
#             step_size /= 2

#         iterations += 1

#         if iterations % 100 == 0:
#             print(
#                 f"Iteration {iterations}, x = {x}, f(x) = {f(x)}, step_size = {step_size}"
#             )

#     return x, path


# if __name__ == "__main__":

#     expr = input("Enter the function in terms of x (-x**2 + 5 or x**2 - 4*x + 4): ")
#     f = lambda x: eval(expr, {"x": x, "np": np})

#     try:
#         x0 = float(input("Enter initial value of x: "))
#     except ValueError:
#         print("Invalid input. Using default value of 0.")
#         x0 = 0

#     result, path = hill_climbing(f, x0)

#     print("\nResults:")
#     print(f"Local maximum found at x = {round(result, 6)}")
#     print(f"Maximum value = {round(f(result), 6)}")
#     print(f"Algorithm took {len(path)} steps")

#     try:
#         padding = max(5, (max(path) - min(path)) * 0.5)
#         x_min = min(path) - padding
#         x_max = max(path) + padding

#         x_values = np.linspace(x_min, x_max, 500)
#         y_values = [f(x) for x in x_values]

#         plt.figure(figsize=(10, 6))

#         plt.plot(x_values, y_values, "b-", label=f"Function: {expr}")

#         path_y = [f(x) for x in path]
#         plt.plot(path, path_y, "r-", alpha=0.5, label="Search path")
#         plt.scatter(path, path_y, color="red", marker="o", s=30, alpha=0.7)

#         plt.scatter(
#             [path[0]],
#             [f(path[0])],
#             color="green",
#             marker="o",
#             s=100,
#             label="Start point",
#         )
#         plt.scatter(
#             [result],
#             [f(result)],
#             color="purple",
#             marker="*",
#             s=200,
#             label="Found maximum",
#         )

#         plt.xlabel("x")
#         plt.ylabel("f(x)")
#         plt.title("Hill Climbing Algorithm Visualization")
#         plt.legend()
#         plt.grid(True)

#         plt.show()
#     except Exception as e:
#         print(f"Couldn't create visualization: {e}")
