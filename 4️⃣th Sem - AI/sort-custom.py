def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


def custom_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        if arr[i] > arr[i + 1]:
            swap(arr, i, i + 1)


arr = list(map(int, input("Enter numbers: ").split()))

print("Original array:", arr)

for _ in range(len(arr)):
    custom_sort(arr)

print("Sorted array:", arr)