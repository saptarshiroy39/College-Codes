row = int(input("Enter number of rows: "))
col = int(input("Enter number of columns: "))
matrix = [[0] * col for j in range(row)]

for i in range(row):
    if i % 2 == 0:
        for j in range(col):
            matrix[i][j] = 1
            print(matrix)
    else:
        for j in range(-1, (col * -1) - 1, -1):
            matrix[i][j] = 1
            print(matrix)

print(matrix)
