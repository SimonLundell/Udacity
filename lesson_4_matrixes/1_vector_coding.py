x0 = [5, 2, 10, 0]
assert x0 == [5, 2, 10, 0]

## TODO: Assign the change in position and velocity to the variable
## xdelta. Remember that the order of the vector is x, y, vx, vy

xdelta = [3, 5, 2, 5]

### Test Case
### Run this test case to see if your results are as expected
### Running this cell should produce no output if all assertions are True

assert xdelta == [3, 5, 2, 5]

## TODO: Add the vectors together element-wise. For example,
## element-wise addition of [2, 6] and [10, 3] is [12, 9].
## Place the answer in the x1 variable.
##
## Hint: You can use a for loop. The append method might also
## be helpful.

x1 = []
length = len(x0)
for n in range(length):
    x = x0[n] + xdelta[n]
    x1.append(x)

### Test Case 
### Run this test case to see if your results are as expected
### Running this cell should produce no output if all assertions are True
assert x1 == [8, 7, 12, 5]

## TODO: Multiply each element in the x1 vector by the conversion
## factor shown belowand store the results in the variable s.
## Use a for loop

meters_to_feet = 1.0 / 0.3048
x1feet =[]
length = len(x1)
for n in range(length):
    x1feet.append(x1[n]*meters_to_feet)

### Test Cases
### Run this test case to see if your results are as expected
### Running this cell should produce no output if all assertions are True
x1feet_sol = [8/.3048, 7/.3048, 12/.3048, 5/.3048]

assert(len(x1feet) == len(x1feet_sol))
for response, expected in zip(x1feet, x1feet_sol):
    assert(abs(response-expected) < 0.001)

## TODO: Fill in the dotproduct() function to calculate the 
## dot product of two vectors.
##

## Here are the inputs and outputs of the dotproduct() function:
##     INPUTS: vector, vector
##     OUTPUT: dot product of the two vectors
##         
##
## The dot product involves mutliplying the vectors element
## by element and then taking the sum of the results
##
## For example, the dot product of [9, 7, 5] and [2, 3, 4] is 
## 9*2+7*3 +5*4 = 59
## 
## Hint: You can use a for loop. You will also need to accumulate
## the sum as you iterate through the vectors. In Python, you can accumulate 
## sums with syntax like w = w + 1

x2 = []

def dotproduct(vectora, vectorb):
    
    # variable for accumulating the sum
    result = 0
    # TODO: Use a for loop to multiply the two vectors
    # element by element. Accumulate the sum in the result variable
    l = len(vectora)
    y = 0
    for n in range(l):
        x = vectora[n]*vectorb[n]
        y = y + x
    result = y
    
    return result  
x2 = [dotproduct([8, 7, 12, 5], [1, 0, 2, 0]), 
      dotproduct([8, 7, 12, 5], [0, 1, 0, 2]),
      12,
      5]
print(x2)

### Test Case
### Run this test case to see if your results are as expected
### Running this cell should produce no output if all assertions are True
assert x2 == [32, 17, 12, 5]
