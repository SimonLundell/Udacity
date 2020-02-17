# The CODE

def dot_product(a, b):
    # start by checking that a and b have the same length.
    # I know they SHOULD have the same length because they
    # each are DEFINED (in the first line above) to have n 
    # elements. Even though n isn't specified, the fact that 
    # a goes from 0 to n AND b does the same (instead of going
    # from 0 to m for example) implies that these vectors 
    # always should have the same length.
    if len(a) != len(b):
        print("Error! Vectors must have the same length!")
        return None
    
    # let's call the length of these vectors "n" so we can
    # be consistent with the mathematical notation
    n = len(a)
    
    # Since we want to add up a bunch of terms, we should
    # start by setting the total to zero and then add to 
    # this total n times.
    total = 0
    
    # now we are going to perform the multiplication!
    # note that the algebraic version goes from 1 to n. 
    # The Python version of this indexing will go from 
    # 0 to n-1 (recall that range(3) returns [0,1,2] for example).
    for i in range(n): 
        a_i = a[i]
        b_i = b[i]
        total = total + a_i * b_i
        
    return total

# let's see if it works
a = [3,2,4]
b = [2,5,9]

# a*b should be 3*2 + 2*5 + 4*9
# or...           6 +  10 +  36
#                            52

a_dot_b = dot_product(a,b)
print(a_dot_b)
