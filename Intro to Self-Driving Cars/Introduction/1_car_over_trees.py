# CODE CELL
# 
# This is the code you should 
# edit and run to control the car.

from Car import Car # you don't need to change this line of code...

def jump(car):
    # TODO - make modifications in this function
    #   so that your car makes it safely over the trees.
    
    car.steer(0.0) # any value between -25 and 25 works here for
                   # steering angle (in degrees)
        
    car.gas(1.0)   # any value between -1.0 (full reverse) and 
                   # 1.0 (full throttle) works here
    
car = Car()  
jump(car)
