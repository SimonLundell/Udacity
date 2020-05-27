# CODE CELL
#
# This is the code you should edit and run to control the car.

from Car import Car
import time

# TODO: Make changes to the steering and gas values and see how they affect the car's motion
def circle(car):
    car.steer(4.5)
    car.gas(0.50)
    
car = Car()

circle(car)

# Observations: Increasing the gas requires a decrease in steer for the car to stay on the circle. Seems to be a relation of roughly 10. Once car stabilizes it is maintaining same circle assuming speed is constant.
