from scipy.stats import norm
import numpy as np


"""
The code cell below calculates a Gaussian probability density function two ways. First, we're using the density function from the previous exercises. Then, we compare the results using the SciPy library's implementation.

You'll see that the results are exactly the same.
"""

# our solution to calculate the probability density function
def gaussian_density(x, mu, sigma):
    return (1/np.sqrt(2*np.pi*np.power(sigma, 2.))) * np.exp(-np.power(x - mu, 2.) / (2 * np.power(sigma, 2.)))

print("Probability density function our solution: mu = 50, sigma = 10, x = 50")
print(gaussian_density(50, 50, 10))
print("\nProbability density function SciPy: mu = 50, sigma = 10, x = 50")
print(norm(loc = 50, scale = 10).pdf(50))

import matplotlib.pyplot as plt
#%matplotlib inline

###
# The plot_fill function plots a probability density function and also
# shades the area under the curve between x_prob_min and x_prob_max.
# INPUTS:
# x: x-axis values for plotting
# x_prob_min: minimum x-value for shading the visualization
# x_prob_max: maximum x-value for shading the visualization
# y_lim: the highest y-value to show on the y-axis
# title: visualization title
#
# OUTPUTS:
# prints out a visualization
###

def plot_fill(x, x_prob_min, x_prob_max, y_lim, title):
    # Calculate y values of the probability density function
    # Note that the pdf method can accept an array of values from numpy linspace.
    y = norm(loc = 50, scale = 10).pdf(x)

    # Calculate values for filling the area under the curve
    x_fill = np.linspace(x_prob_min, x_prob_max, 1000)
    y_fill = norm(loc = 50, scale = 10).pdf(x_fill)

    # Plot the results
    plt.plot(x, y)
    plt.fill_between(x_fill, y_fill)
    plt.title(title)
    plt.ylim(0, y_lim)
    plt.xticks(np.linspace(0, 100, 21))
    plt.xlabel('Temperature (Fahrenheit)')
    plt.ylabel('probability density function')
    plt.show()

average = 50
stdev = 10
y_lim = 0.05
x = np.linspace(0, 100, 1000)

plot_fill(x, 0, 50, y_lim,
          'Gaussian Distribution, Average = ' + str(average) + ', Stdev ' + str(stdev))

"""
Here are a few more examples of the cdf method. The code cell below prints out the probability that the temperature is between:

    -infinity and 25
    -infinity and 75
    -infinity and 125
    -infinity and +infinity
"""

print(norm(loc = 50, scale = 10).cdf(25))
print(norm(loc = 50, scale = 10).cdf(75))
print('%.20f' % norm(loc = 50, scale = 10).cdf(125)) # '%.20f' prints out 20 decimal places
print(norm(loc = 50, scale = 10).cdf(float('inf')))

#What if you wanted to know the probability of the temperature being between 25 and +infinity? Or 75 and +infinity? 

print(1 - norm(loc = 50, scale = 10).cdf(25))

#Calculating Area Under the Curve Solution

from scipy.stats import norm

def gaussian_probability(mean, stdev, x_low, x_high):
    return norm(loc = mean, scale = stdev).cdf(x_high) - norm(loc = mean, scale = stdev).cdf(x_low)

