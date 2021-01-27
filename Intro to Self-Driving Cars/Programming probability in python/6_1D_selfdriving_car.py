import matplotlib.pyplot as plt
import numpy as np

def initialize_robot(grid_size):
    
    grid = []
    
    # TODO: for each space on the map grid, store the initial probability
    # in the grid list. For example, if there are eight spaces on the grid,
    # the grid list should have eight entries where each entry represents
    # the initial probability of the robot being in that space.
    for i in range(grid_size):
        grid.append(1/grid_size)
    
    return grid

# Result should be a list with 9 elements all having value 1/9
assert initialize_robot(9) == [1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9, 1/9]

# Result should be a list with 4 elements all having value 1/4
assert initialize_robot(4) == [1/4, 1/4, 1/4, 1/4]

print('Hooray! You just initialized a discrete probability distribution')

def grid_probability(grid, position):

    #####
    # TODO: Use an if statement to make sure that the position input
    # does not go beyond the size of the list. Say the list has five elements
    # and your code tries to access grid[5] or grid[6]. That will lead to an
    # error.

    if (position > (len(grid)-1)):
        print('position is outside the grid')
        return None

    # TODO: If the position input is legitimate, then return the probability
    # stored at that position. If the position input is not legitimate, then
    # return None
    #####

    grid = grid[position]
    print(grid)

    return grid
assert grid_probability([.1, .1, .2, .1, .5], 2) == 0.2

assert grid_probability([.1, .1, .2, .1, .5], 7) == None

print('Awesome work!')

def output_map(grid):

    ###
    # TODO: Start by creating a list to represent the x-axis labels.
    # For example, if the grid variable has length 5, x_labels would contain
    # a list [0, 1, 2, 3, 4].
    #
    # HINT: Python's built in len() and range() functions might
    #       be useful. If you are not sure how to use these
    #       functions, look them up in a search engine.
    #       For example, in google, look up "Python len".
    ###

    x_labels = np.array([x for x in range(len(grid))])

    ###
    # TODO: Using matplotlib, output a bar chart of the results.
    # Notice that we have already imported the matplotlib library
    # at the top of this code cell.

    # If you are unsure how to make a bar chart, go back to the
    # "Plotting in Python demonstration" to see an example.

    # Make sure your plot has an xlabel, a ylabel, and a title
    # Don't forget that the last line needs to be plt.show() so
    # that your visualization prints out to the screen.

    #plt.plot([x_labels[0], x_labels[1]], [grid, grid], color='blue')
    #plt.plot([0, 0], [0, y], '--', color='blue', )
    #plt.plot([360, 360], [0, y], '--', color='blue', )
    #plt.ylim([0, y + y/2])

    plt.bar(x_labels, grid) #(x-value, y-value)
    plt.xlabel('Grid space')
    plt.ylabel('Probability')
    plt.title('Probability of the robot being at each space on the grid')
    plt.show()

output_map([.2, .2, .2, .2, .2])

def update_probabilities(grid, updates):

    ###
    # TODO: write a for loop that goes through the updates list
    # and replaces the probabilities in the grid variable.
    #
    # Here are a few HINTS:
    #     You can change a value in the grid variable like this:
    #         grid[0] = .5  where the 0 represents the first grid space
    #
    #     To access values in a list of lists, you need two brackets.
    #
    #     For example, say
    #     updates = [[5, 0.15], [0, .4], [3, 0.15], [1, 0.15], [2, 0.15]]
    #
    #     updates[0] will give you access to the first element in the list,
    #        which  is [5, 0.15].
    #
    #     updates[0][0] gives you access to the first element of [5, 0.15]
    #        or in other words the value 5. updates[0][1] gives you access
    #        to the value 0.15.
    #
    ###

    for x in range(len(updates)):
        grid[updates[x][0]] = updates[x][1]

    return grid

assert update_probabilities([0.2, 0.2, 0.2, 0.2, 0.2], [[0, .4], [1, 0.15], [2, 0.15], [3, 0.15], [4, 0.15]]) == [0.4, 0.15, 0.15, 0.15, 0.15]
assert update_probabilities([0.2, 0.2, 0.2, 0.2, 0.2], [[1, 0.15], [0, .4], [4, 0.15], [2, 0.15], [3, 0.15]]) == [0.4, 0.15, 0.15, 0.15, 0.15]
assert update_probabilities([0.2, 0.2, 0.2, 0.2, 0.2], [[0, .25], [4, 0.15]]) == [0.25, 0.2, 0.2, 0.2, 0.15]

print('Everything looks good!')
