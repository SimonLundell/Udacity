import math
from math import sqrt
import numbers

def zeroes(height, width):
        """
        Creates a matrix of zeroes.
        """
        g = [[0.0 for _ in range(width)] for __ in range(height)]
        return Matrix(g)

def identity(n):
        """
        Creates a n x n identity matrix.
        """
        I = zeroes(n, n)
        for i in range(n):
            I.g[i][i] = 1.0
        return I

class Matrix(object):

    # Constructor
    def __init__(self, grid):
        self.g = grid
        self.h = len(grid)
        self.w = len(grid[0])

    #
    # Primary matrix math methods
    #############################
 
    def determinant(self):
        """
        Calculates the determinant of a 1x1 or 2x2 matrix.
        """
        if not self.is_square():
            raise(ValueError, "Cannot calculate determinant of non-square matrix.")
        if self.h > 2:
            raise(NotImplementedError, "Calculating determinant not implemented for matrices largerer than 2x2.")
        
        if self.h == 1:
            return self
        
        else:
            a = self[0][0]
            b = self[0][1]
            c = self[1][0]
            d = self[1][1]
            
            return a*d - b*c

    def trace(self):
        """
        Calculates the trace of a matrix (sum of diagonal entries).
        """
        trace = 0
        
        if not self.is_square():
            raise(ValueError, "Cannot calculate the trace of a non-square matrix.")

        if self.h == 1:
            return self
        
        else:
            for i in range(self.h):
                trace = trace + self[i][i]
            
            return trace

    def inverse(self):
        """
        Calculates the inverse of a 1x1 or 2x2 Matrix.
        """
        if not self.is_square():
            raise(ValueError, "Non-square Matrix does not have an inverse.")
        if self.h > 2:
            raise(NotImplementedError, "inversion not implemented for matrices larger than 2x2.")

        if self.h == 1:
            self[0][0] = 1/self[0][0]
            return self
        
        else:
            a = self[0][0]
            b = self[0][1]
            c = self[1][0]
            d = self[1][1]
            tot = (a*d - b*c)
          
            if tot == 0:
                raise ValueError('The matrix is non-invertible')
            else:
                inverse = [[d, -b],[-c, a]]
            
            for i in range(len(inverse)):
                for j in range(len(inverse[0])):
                    inverse[i][j] = (1 / tot) * inverse[i][j]
            
            ret = Matrix(inverse)
            print(ret)
            return ret
            

    def T(self):
        """
        Returns a transposed copy of this Matrix.
        """
        
        matrix_transpose = []
    
        l = self.h
        k = self.w

        for i in range(k):
            e = []
            for j in range(l):
                x = self[j][i]
                e.append(x)
            matrix_transpose.append(e)
        
        ret = Matrix(matrix_transpose)
        
        return ret
            

    def is_square(self):
        return self.h == self.w

    #
    # Begin Operator Overloading
    ############################
    def __getitem__(self,idx):
        """
        Defines the behavior of using square brackets [] on instances
        of this class.

        Example:

        > my_matrix = Matrix([ [1, 2], [3, 4] ])
        > my_matrix[0]
          [1, 2]

        > my_matrix[0][0]
          1
        """
        return self.g[idx]

    def __repr__(self):
        """
        Defines the behavior of calling print on an instance of this class.
        """
        s = ""
        for row in self.g:
            s += " ".join(["{} ".format(x) for x in row])
            s += "\n"
        return s

    def __add__(self,other):
        """
        Defines the behavior of the + operator
        """
        row = []
        matsum = []
        if self.h != other.h or self.w != other.w:
            raise(ValueError, "Matrices can only be added if the dimensions are the same") 
        #   
        else:
            for x in range(self.h):
                for y in range(self.w):
                    a = self[x][y]
                    b = other[x][y]
                    c = a + b
                    row.append(c)
                matsum.append(row)
                row = []
        
        tot = Matrix(matsum)
        return tot
        #

    def __neg__(self):
        """
        Defines the behavior of - operator (NOT subtraction)

        Example:

        > my_matrix = Matrix([ [1, 2], [3, 4] ])
        > negative  = -my_matrix
        > print(negative)
          -1.0  -2.0
          -3.0  -4.0
        """
        #
        matsum = []
        row = []
        for x in range(self.h):
            for y in range(self.w):
                neg = self[x][y] * -1
                row.append(neg)
            matsum.append(row)
            row = []
        
        tot = Matrix(matsum)
        return tot
                
        #

    def __sub__(self, other):
        """
        Defines the behavior of - operator (as subtraction)
        """
        row = []
        matsum = []
        if self.h != other.h or self.w != other.w:
            raise(ValueError, "Matrices can only be added if the dimensions are the same") 
        #   
        else:
            for x in range(self.h):
                for y in range(self.w):
                    a = self[x][y]
                    b = other[x][y]
                    c = a - b
                    row.append(c)
                matsum.append(row)
                row = []
        
        ret = Matrix(matsum)
        
        return ret

    def __mul__(self, other):
        """
        Defines the behavior of * operator (matrix multiplication)
        """
        #
        def get_row(matrix, row):
            return matrix[row]
        
        def get_column(matrix, column_number):
            column = []
            for i in range(len(matrix)):
                x = matrix[i][column_number]
                column.append(x)
            
            return column
        
        def dot_product(vector_one, vector_two):
            y = 0
            for i in range(len(vector_one)):
                x = vector_one[i]*vector_two[i]
                y = y + x
            
            return y
        
        m_rows = self.h
        p_columns = len(other.g[0])
        result = []
        
        for r in range(m_rows):
            row_result = []
            extracted_row = get_row(self, r)
            for c in range(p_columns):
                extracted_col = get_column(other.g, c)
                dot_prod = dot_product(extracted_row, extracted_col)
                row_result.append(dot_prod)
    
            result.append(row_result)
        
        matsum = Matrix(result)
        
        return matsum
        
        
        #

    def __rmul__(self, other):
        """
        Called when the thing on the left of the * is not a matrix.

        Example:

        > identity = Matrix([ [1,0], [0,1] ])
        > doubled  = 2 * identity
        > print(doubled)
          2.0  0.0
          0.0  2.0
        """
        if isinstance(other, numbers.Number):
            
            #
            val = other
            matsum = []
            row = []
            for x in range(self.h):
                for y in range(self.w):
                    doub = self[x][y] * val
                    row.append(doub)
                matsum.append(row)
                row = []
        
            tot = Matrix(matsum)
            return tot
            #
            