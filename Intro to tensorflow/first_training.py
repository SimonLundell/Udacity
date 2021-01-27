import tensorflow as tf
import numpy as np
import logging
import matplotlib.pyplot as plt

logger = tf.get_logger()
logger.setLevel(logging.ERROR)

# Setting up some training data
celsius_q = np.array([-40, -10, 0, 8, 15, 22, 38], dtype=float)
fahrenheit_a = np.array([-40, 14, 32, 46, 59, 72, 100], dtype=float)

for i, c in enumerate(celsius_q):
    print("{} degree celsius = {} degree fahrenheit".format(c, fahrenheit_a[i]))

# Next, build a layer
"""
Since the function is very simple, a dense layer is sufficient. units specifies the number of neurons in the layer, this needs to match the input shape of the next layer in a multi-layer network, but we only have 1 layer. input_shape specifies the input to the layer is a single value (1-D array with one member), a single float point of degrees celsius
"""
l0 = tf.keras.layers.Dense(units=1, input_shape=[1])

# Next, all layers needs to be assembled into a model
model = tf.keras.Sequential([l0])

# Before training, we have to compile the model
"""
In the compiler we define:
- how to measure the loss (how far off from the predictions can our final outcome be)
- Optimizer - a way of adjusting the internal values to reduce the loss. There are many available, and the value specified is how big the steps should be between each adjustment (too low -> too slow, too big -> too inaccurate)
"""
model.compile(loss='mean_squared_error', optimizer=tf.keras.optimizers.Adam(0.1))

# Now we train the model using the .fit function
"""
We will feed the .fit function with the input, output, epochs (cycles to run the function), verbose (how much output we should produce
"""
history = model.fit(celsius_q, fahrenheit_a, epochs=500, verbose=False)
print("Finished training the model")

plt.xlabel('Epoch number')
plt.ylabel('Loss magnitude')
plt.plot(history.history['loss'])
plt.show()

# Now that the model is trained, we can give it an input value and it will predict the outcome (correct answer is 212.
print(model.predict([100.0]))

# We can also print the weights
print("These are the layer variables: {}".format(l0.get_weights()))

# For fun, lets put in some more layers
l0 = tf.keras.layers.Dense(units=4, input_shape=[1])
l1 = tf.keras.layers.Dense(units=4)
l2 = tf.keras.layers.Dense(units=1)
model = tf.keras.Sequential([l0, l1, l2])
model.compile(loss='mean_squared_error', optimizer=tf.keras.optimizers.Adam(0.1))
model.fit(celsius_q, fahrenheit_a, epochs=500, verbose=False)
print("Finished training the model")
print(model.predict([100.0]))


