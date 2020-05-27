# Constant acceleration, changing velocity

# initial variables
x = 0
velocity = 50
acc = -20

initial_state = [x, velocity, acc]

# predicted state after three seconds have elapsed
# this state has a new value for x, and a new value for velocity (but the acceleration stays the same)
dt = 3

new_x = x + velocity*dt + 0.5*acc*dt**2
new_vel = velocity + acc*dt

predicted_state = [new_x, new_vel, acc]  # predicted_state = [60, -10, -20]# Constant acceleration, changing velocity

# initial variables
x = 0
velocity = 50
acc = -20

initial_state = [x, velocity, acc]

# predicted state after three seconds have elapsed
# this state has a new value for x, and a new value for velocity (but the acceleration stays the same)
dt = 3

new_x = x + velocity*dt + 0.5*acc*dt**2
new_vel = velocity + acc*dt

predicted_state = [new_x, new_vel, acc]  # predicted_state = [60, -10, -20]
