# Constant velocity case

# initial variables
x = 0
velocity = 50
initial_state = [x, velocity]

# predicted state (after three seconds)
# this state has a new value for x, but the same velocity as in the initial state
dt = 3
new_x = x + velocity*dt
predicted_state = [new_x, velocity]  # predicted_state = [150, 50]


