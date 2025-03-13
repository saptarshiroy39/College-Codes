def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


def custom_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        if arr[i] > arr[i + 1]:
            swap(arr, i, i + 1)


def main():
    arr = list(map(int, input("Enter numbers separated by spaces: ").split()))

    print("Original array:", arr)

    for _ in range(len(arr)):
        custom_sort(arr)

    print("Sorted array:", arr)


if __name__ == "__main__":
    main()
