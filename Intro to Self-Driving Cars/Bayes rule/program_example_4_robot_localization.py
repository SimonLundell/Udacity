import numpy as np

# A 4x5 robot world of characters 'o' and 'b'
world = np.array([ ['o', 'b', 'o', 'o', 'b'],
                   ['o', 'o', 'b', 'o', 'o'],
                   ['b', 'o', 'o', 'b', 'o'],
                   ['b', 'o', 'o', 'o', 'o'] ])

# Sensor measurement
measurement = ['b', 'o']

# This function takes in the world and the sensor measurement.
# Complete this function so that it returns the indices of the 
# likely robot locations, based on matching the measurement 
# with the color patterns in the world

def find_match(world, measurement):
    # Empty possible_locations list
    possible_locations = []
    trial_list = []
    
    for x in range(0,world.shape[0]):
        for y in range(0,(world.shape[1])-1):
            trial_list.append(world[x][y])
            trial_list.append(world[x][y+1])
            
            if trial_list == measurement:
                possible_locations.append([x, y])
            trial_list = []

    ## TODO: Iterate through the world 
    ## Look at two adjacent indices at a time - the square the robot is 
    ## on top of and the square to its right
    ## (Making sure not to go past the bounds of the world)
    
    ## TODO: If two adjacent colors in the world match 
    ## the two colors in the sensor measurement
    ## Add those indices to the possible_locations list
    ## Append them in the format [row_index, column_index], i.e. [0, 0]
    return possible_locations
   

# This line runs the function and stores the output - do not delete 
locations = find_match(world, measurement)
