## TODO: Run this code cell to load the get_row function
## You do not need to modify this cell

def get_row(matrix, row):
    return matrix[row]

### TODO: Write a function that receives a matrix and a column number.
###       the output should be the column in the form of a list


### Example input:
# matrix = [
#    [5, 9, 11, 2],
#    [3, 2, 99, 3],
#    [7, 1, 8, 2]
# ]
#
# column_number = 1

### Example output:
# [9, 2, 1]
#

def get_column(matrix, column_number):
    column = []
    for i in range(len(matrix)):
        x = matrix[i][column_number]
        column.append(x)
    return column

### TODO: Run this code to test your get_column function
assert get_column([[1, 2, 4],
                   [7, 8, 1],
                   [5, 2, 1]], 1) == [2, 8, 2]

assert get_column([[5]], 0) == [5]

### TODO: Write a function called dot_product() that
###       has two vectors as inputs and outputs the dot product of the
###       two vectors. First, you will need to do element-wise
###       multiplication and then sum the results.

### HINT: You wrote this function previously in the vector coding
###        exercises

def dot_product(vector_one, vector_two):
    y = 0
    for i in range(len(vector_one)):
        x = vector_one[i]*vector_two[i]
        y = y + x
    return y

### TODO: Run this cell to test your results

assert dot_product([4, 5, 1], [2, 1, 5]) == 18
assert dot_product([6], [7]) == 42

### TODO: Write a function called matrix_multiplication that takes
###       two matrices,multiplies them together and then returns
###       the results
###
###       Make sure that your function can handle matrices that contain
###       only one row or one column. For example,
###       multiplying two matrices of size (4x1)x(1x4) should return a
###       4x4 matrix

def matrix_multiplication(matrixA, matrixB):

    ### TODO: store the number of rows in A and the number
    ###       of columns in B. This will be the size of the output
    ###       matrix
    ### HINT: The len function in Python will be helpful
    m_rows = len(matrixA)
    p_columns = len(matrixB[0])


    # empty list that will hold the product of AxB
    result = []

    ### TODO:  Write a for loop within a for loop. The outside
    ###        for loop will iterate through m_rows.
    ###        The inside for loop will iterate through p_columns.
    for r in range(m_rows):
        row_result = []
        extracted_row = get_row(matrixA, r)
        for c in range(p_columns):
            extracted_col = get_column(matrixB, c)
            dot_prod = dot_product(extracted_row, extracted_col)
            row_result.append(dot_prod)

        result.append(row_result)


    ### TODO:  As you iterate through the m_rows and p_columns,
    ###        use your get_row function to grab the current A row
    ###        and use your get_column function to grab the current
    ###        B column.


    ### TODO: Calculate the dot product of the A row and the B column


    ### TODO: Append the dot product to an empty list called row_result.
    ###       This list will accumulate the values of a row
    ###        in the result matrix



    ### TODO: After iterating through all of the columns in matrix B,
    ###       append the row_result list to the result variable.
    ###       Reinitialize the row_result to row_result = [].
    ###       Your for loop will move down to the next row
    ###       of matrix A.
    ###       The loop will iterate through all of the columns
    ###       taking the dot product
    ###       between the row in A and each column in B.

    ### TODO: return the result of AxB

    print(result)
    return result

### TODO: Run this code cell to test your results
assert matrix_multiplication([[5], [2]], [[5, 1]]) == [[25, 5], [10, 2]]
assert matrix_multiplication([[5, 1]], [[5], [2]]) == [[27]]
assert matrix_multiplication([[4]], [[3]]) == [[12]]
assert matrix_multiplication([[2, 1, 8, 2, 1], [5, 6, 4, 2, 1]], [[1, 7, 2], [2, 6, 3], [3, 1, 1], [1, 20, 1], [7, 4, 16]]) == [[37, 72, 33], [38, 119, 50]]
