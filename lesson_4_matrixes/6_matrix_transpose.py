### TODO: Write a function called transpose() that 
###       takes in a matrix and outputs the transpose of the matrix

def transpose(matrix):
    matrix_transpose = []
    
    l = len(matrix)
    k = len(matrix[0])

    for i in range(k):
        e = []
        for j in range(l):
            x = matrix[j][i]
            e.append(x)
        matrix_transpose.append(e)
    
    print(matrix_transpose)
    return matrix_transpose

### TODO: Run the code in the cell below. If there is no
###       output, then your answers were as expected

assert transpose([[5, 4, 1, 7], [2, 1, 3, 5]]) == [[5, 2], [4, 1], [1, 3], [7, 5]]
assert transpose([[5]]) == [[5]]
assert transpose([[5, 3, 2], [7, 1, 4], [1, 1, 2], [8, 9, 1]]) == [[5, 7, 1, 8], [3, 1, 1, 9], [2, 4, 2, 1]]

### TODO: Write a function called matrix_multiplication() that
###       takes in two matrices and outputs the product of the two
###       matrices

### TODO: Copy your dot_product() function here so that you can
###       use it in your matrix_multiplication function
def dot_product(vector_one, vector_two):
    y = 0
    for i in range(len(vector_one)):
        x = vector_one[i]*vector_two[i]
        y = y + x
    return y

def identity_matrix(n):
    
    identity = []
    
    # TODO: Write a nested for loop to iterate over the rows and
    # columns of the identity matrix. Remember that identity
    # matrices are square so they have the same number of rows
    # and columns
    
    # Make sure to assign 1 to the diagonal values and 0 everywhere
    # else
    
    for i in range(n):
        x = []
        for j in range(n):
            if i == j:
                x.append(1)
            else:
                x.append(0)
        identity.append(x)
    
    print(identity)
    return identity

def matrix_multiplication(matrixA, matrixB):
    product = []


    ## TODO: Take the transpose of matrixB and store the result
    ##       in a new variable
    trans_matrixB = transpose(matrixB)

    ## TODO: Use a nested for loop to iterate through the rows
    ## of matrix A and the rows of the tranpose of matrix B
    for i in range(len(matrixA)):
        x = []
        for j in range(len(trans_matrixB)):
            x.append(dot_product(trans_matrixB[j], matrixA[i]))
        product.append(x)

    ## TODO: Calculate the dot product between each row of matrix A
    ##         with each row in the transpose of matrix B

    ## TODO: As you calculate the results inside your for loops,
    ##       store the results in the product variable


    ## TODO:
    print(product)
    return product

### TODO: Run the code in the cell below. If there is no
###       output, then your answers were as expected
m = [[5, 9, 2, 4],
     [3, 8, 5, 6],
     [1, 0, 0, 15]]

assert matrix_multiplication(m, identity_matrix(4)) == m
assert matrix_multiplication(identity_matrix(3), m) == m

assert matrix_multiplication([[5, 3, 1],
                              [6, 2, 7]],
                             [[4, 2],
                              [8, 1],
                              [7, 4]]) == [[51, 17],
                                           [89, 42]]

assert matrix_multiplication([[5]], [[4]]) == [[20]]

assert matrix_multiplication([[2, 8, 1, 2, 9],
                             [7, 9, 1, 10, 5],
                             [8, 4, 11, 98, 2],
                             [5, 5, 4, 4, 1]],
                             [[4],
                              [2],
                              [17],
                              [80],
                              [2]]) == [[219], [873], [8071], [420]]


assert matrix_multiplication([[2, 8, 1, 2, 9],
                             [7, 9, 1, 10, 5],
                             [8, 4, 11, 98, 2],
                             [5, 5, 4, 4, 1]],
                             [[4, 1, 2],
                              [2, 3, 1],
                              [17, 8, 1],
                              [1, 3, 0],
                              [2, 1, 4]]) == [[61, 49, 49], [83, 77, 44], [329, 404, 39], [104, 65, 23]]
