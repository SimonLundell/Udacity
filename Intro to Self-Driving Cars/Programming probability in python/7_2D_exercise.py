def initial_grid(rows, columns):

    # TODO: initialize an empty list in a variable called grid
    grid = []
    
    # TODO: initialize an empty row in a variable called row
    row = []

    # TODO: calculate the initial probability
    probability = float(1) / (rows * columns)
    
    # TODO: write a nested for loop that appends values to the grid variable
    # HINT: You first need to fill in a row with values and then append the row to the grid.
    #        Then you'll need to set the row variable to an empty list.
    #        The logic of all this can be tough to think through. 
    #        If you get stuck, see the demonstrations in the previous part of the lesson
    
    for x in range(rows):
        row = []
        for y in range(columns):
            row.append(probability)
        grid.append(row)
    print grid
    return grid

assert initial_grid(5, 4) == [[0.05, 0.05, 0.05, 0.05],
                              [0.05, 0.05, 0.05, 0.05],
                              [0.05, 0.05, 0.05, 0.05],
                              [0.05, 0.05, 0.05, 0.05],
                              [0.05, 0.05, 0.05, 0.05]]

assert initial_grid(2, 5) == [[0.1, 0.1, 0.1, 0.1, 0.1],
                              [0.1, 0.1, 0.1, 0.1, 0.1]]

assert initial_grid(2, 2) == [[0.25, 0.25],
                              [0.25, 0.25]]

print('Hooray!')

def probability(grid, row, column):

    # TODO: return the probability that the robot as at the space representing by the row and column values.
    result = grid[row][column]

    return result

assert probability([[.25, .1],
                    [.45, .2]],
                   1, 1) == 0.2

assert probability([[.05, .1, .1],
                    [.04, .3, .02],
                    [.01, .02, .02],
                    [.005, .012, .06],
                    [.09, .07, .103]], 3, 2) == 0.06

assert probability([[.05, .1, .1],
                    [.04, .3, .02],
                    [.01, .023, .017],
                    [.005, .012, .06],
                    [.09, .07, .103]], 2, 2) == .017

print('You passed all the assertion tests.')

import matplotlib.pyplot as plt
#%matplotlib inline

def graph_grid(grid):
    plt.imshow(grid, cmap='Greys', clim=(0,.1))
    plt.title('Heat Map of Grid Probabilities')
    plt.xlabel('grid x axis')
    plt.ylabel('grid y axis')
    plt.legend()
    plt.show()

grid = [[.05, .1, .1],
        [.04, .3, .02],
        [.01, .023, .017],
        [.005, .012, .06],
        [.09, .07, .103]]

graph_grid(grid)

# Example of nested lists

update_list = [
              [[4,2], 0.012],
              [[2,2], 0.108],
              [[0,1], 0.004],
              [[3,0], 0.101]
              ]

# Code for accessing the first element in the list
print(update_list[0])
print(update_list[0][0])
print(update_list[0][0][0])
print(update_list[0][0][1])
print(update_list[0][1])

# Output of for loop
print('\noutput of for loop')
for element in update_list:
    print(element)

print('\noutput rows and columns with probability')
for element in update_list:
    row, col = element[0]
    probability = element[1]
    print('row ', row, 'col ', col, 'probability ', probability)


def update_probability(grid, update_list):

    #### TODO:
    # Use the update_list probabilities to update the probabilities in the grid variable.
    # For example, if the grid is

    # grid = [[.05, .1, .1],
    #    [.04, .3, .02],
    #    [.01, .023, .017],
    #    [.005, .012, .06],
    #    [.09, .07, .103]]

    # update_list = [[4, 2], 0.012]]

    # So the element in row 5, column 3 (remember Python does zero indexing) would be
    # changed from 0.103 to 0.012
    for y in range(len(update_list)):
        grid[update_list[y][0][0]][update_list[y][0][1]] = update_list[y][1]
    print(grid)
    return grid

grid = [[.05, .1, .1],
        [.04, .3, .02],
        [.01, .023, .017],
        [.005, .012, .06],
        [.09, .07, .103]]

update_list = [
              [[4,2], 0.012],
              [[2,2], 0.108],
              [[0,1], 0.004],
              [[3,0], 0.101]
              ]

assert update_probability(grid, update_list) == [[0.05, 0.004, 0.1],
 [0.04, 0.3, 0.02],
 [0.01, 0.023, 0.108],
 [0.101, 0.012, 0.06],
 [0.09, 0.07, 0.012]]

print('Nicely done')


"""
Alternative solution last code:

for element in update_list:
    x, y = element[0]
    grid[x][y] = element[1]

return grid

"""
