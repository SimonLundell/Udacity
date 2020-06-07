from testing import test_get_speeds, test_get_x_y, test_get_headings
from helpers import process_data
import solution
import math
from matplotlib import pyplot as plt
import numpy as np

data_list = process_data("trajectory_example.pickle")

def get_speeds(data_list):
    acceleration = [i[3] for i in data_list] # Create array of acceleration data
    times = [i[0] for i in data_list] # Create array of timestamps
    
    speed = 0.0 # Initial speed is 0
    previous_time = times[0] # Initializing the variable
    
    speed_list = [speed] # Creating list of speeds, first speed 0
       
    for i in range(1, len(times)): # Integrating the acceleration data to get speed
        delta_time = times[i] - previous_time
        dSpeed = delta_time * acceleration[i]
        speed += dSpeed
        
        speed_list.append(speed)
        
        previous_time = times[i] # Setting a new previous time
    
    return speed_list

def get_headings(data_list):
    times = [i[0] for i in data_list] # Create array of timestamp data
    yawRate = [i[2] for i in data_list] # Create array of yawRate data
    
    heading = 0.0
    previous_time = times[0]
    
    heading_list = [heading]
    
    for i in range(1, len(times)): # Integrating the yawRate data to get the heading
        delta_time = times[i] - previous_time
        dHeading = yawRate[i] * delta_time
        heading += dHeading
        
        heading_list.append(heading)
        
        previous_time = times[i]
    
    return heading_list

def get_x_y(data_list):
    headings = get_headings(data_list) # Calling function to get the headings
    displacements = [i[1] for i in data_list] # Create array of displacement data
    previous_displacement = displacements[0]
    x = 0.0 # Initializing x,y variables
    y = 0.0
    coords = [(x, y)] # Setting initial coordinates to (0, 0)
    
    for i in range(1, len(displacements)):
        dDisplacement = displacements[i] - previous_displacement # Calculating the distance moved between each sample
        x += dDisplacement * math.cos(headings[i]) # Calculating new x-coordinate and adding it to previous x for total distance
        y += dDisplacement * math.sin(headings[i]) # Calculating new y-coordinate and adding it to previous y for total distance
        coords.append((x, y))
        
        previous_displacement = displacements[i]
        
    return coords

def show_x_y(data_list, increment=1):
    """
    X = [i for i, j in get_x_y(data_list)]
    Y = [j for i, j in get_x_y(data_list)]
    
    plt.scatter(X, Y)
    plt.plot(X, Y)
    plt.show()
    """
    XY = get_x_y(data_list)
    headings = get_headings(data_list)
    X  = [d[0] for d in XY]
    Y  = [d[1] for d in XY]
    h_x = np.cos(headings)
    h_y = np.sin(headings)
    Q = plt.quiver(X[::increment],
                   Y[::increment],
                   h_x[::increment],
                   h_y[::increment],
                   units='x',
                   pivot='tip')
    qk = plt.quiverkey(Q, 0.9, 0.9, 2, r'$1 \frac{m}{s}',
                       labelpos='E', coordinates='figure')
    plt.show()
    return

test_get_speeds(get_speeds)
test_get_headings(get_headings)
test_get_x_y(get_x_y)
show_x_y(data_list)
