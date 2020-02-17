### TODO: Assign the vector <5, 10, 2, 6, 1> to the variable v
v = [5,10,2,6,1]

### TODO: Assign the vector <5, 10, 2, 6, 1> to the variable mv
### The difference between a vector and a matrix in Python is that
### a matrix is a list of lists.

### Hint: See the last quiz on the previous page

mv = [v]

### TODO: Assign the vector <5, 10, 2, 6, 1> to the variable vT
### vT is a 5x1 matrix
vT = [[5],[10],[2],[6],[1]]

### TODO: Assign the following matrix to the variable m
### 8 7 1 2 3
### 1 5 2 9 0
### 8 2 2 4 1

m = [[8,7,1,2,3],
     [1,5,2,9,0],
     [8,2,2,4,1]]

### TODO: In matrix m, change the value
###       in the second row last column from 0 to 5
### Hint: You do not need to rewrite the entire matrix
m[1][4]=5
print(m)

### TODO: Use for loops to multiply each matrix element by 5
###       Store the answer in the r variable. This is called scalar
###       multiplication
###
### HINT: First write a for loop that iterates through the rows
###       one row at a time
###
###       Then write another for loop within the for loop that
###       iterates through the columns
###
###       If you used the variable i to represent rows and j
###       to represent columns, then m[i][j] would give you
###       access to each element in the matrix
###
###       Because r is an empty list, you cannot directly assign
###       a value like r[i][j] = m[i][j]. You might have to
###       work on one row at a time and then use r.append(row).
r = []
for i in range(len(m)):
    n = []
    for j in range(len(m[i])):
        x = 5*m[i][j]
        n.append(x)
    r.append(n)
print(r)

### TODO: Write a function called matrix_print()
###       that prints out a matrix in
###       a way that is easy to read.
###       Each element in a row should be separated by a tab
###       And each row should have its own line
###       You can test our your results with the m matrix

### HINT: You can use a for loop within a for loop
### In Python, the print() function will be useful
### print(5, '\t', end = '') will print out the integer 5,
###    then add a tab after the 5. The end = '' makes sure that
###    the print function does not print out a new line if you do
###    not want a new line.

### Your output should look like this
### 8   7   1   2   3
### 1   5   2   9   5
### 8   2   2   4   1

def matrix_print(matrix):
    for i in range(len(m)):
        for j in range(len(m[i])):
            x = m[i][j]
            print x, ' \t',
        print('\n')
    return

m = [
    [8, 7, 1, 2, 3],
    [1, 5, 2, 9, 5],
    [8, 2, 2, 4, 1]
]

matrix_print(m)

### You can run these tests to see if you have the expected
### results. If everything is correct, this cell has no output

assert v == [5, 10, 2, 6, 1]
assert mv == [
    [5, 10, 2, 6, 1]
]

assert vT == [
    [5],
    [10],
    [2],
    [6],
    [1]]

assert m == [
    [8, 7, 1, 2, 3],
    [1, 5, 2, 9, 5],
    [8, 2, 2, 4, 1]
]

assert r == [
    [40, 35, 5, 10, 15],
    [5, 25, 10, 45, 25],
    [40, 10, 10, 20, 5]
]

print(v)
print(mv)
print(vT)
print(m)
print(r)
