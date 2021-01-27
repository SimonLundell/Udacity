import math

def gaussian(x, sigma, mu):
    result = []
    bottom1 = math.sqrt(2 * math.pi * sigma**2)
    bottom2 = float(2*sigma**2)
    for val in x:
        top2 = float(-(val-mu)**2)
        gauss = (float(1) / bottom1) * math.e**(top2 / bottom2)
        result.append(gauss)
    
    return result

#print gaussian([29,45,48,50,62,78])
def gaussian2(x, sigma, mu):
    result = []
    bottom1 = math.sqrt(2 * math.pi * sigma**2)
    bottom2 = float(2*sigma**2)
    top2 = float(-(x-mu)**2)
    gauss = (float(1) / bottom1) * math.e**(top2 / bottom2)
    result.append(gauss)
    
    return result
print gaussian2(8, 2, 10)

"""
def gaussian_density(x, mu, sigma):
    # TODO: Return the probability density function for the
    # Gaussian distribution.

    bottom1 = np.sqrt(2 * np.pi * sigma**2)
    bottom2 = 2*sigma**2
    top2 = -(x-mu)**2
    gauss = (1 / bottom1) * np.e**(top2 / bottom2)

    return gauss

# Run this code sell to check your results

# numpy linespace creates a list of values called an array
x = np.linspace(0, 100, 11)

### Expected Answer when running the code cell
answer = np.array(([  1.48671951e-07,   1.33830226e-05,   4.43184841e-04,
                      5.39909665e-03,   2.41970725e-02,   3.98942280e-02,
                      2.41970725e-02,   5.39909665e-03,   4.43184841e-04,
                      1.33830226e-05,   1.48671951e-07]))

# Call our function with `gaussian_density(x, 50, 10)` and compare to the answer above
# `assert_almost_equal` is more reliable with floating point numbers than `assert_array_equal`
np.testing.assert_almost_equal(gaussian_density(x, 50, 10), answer, decimal=7)
print("Test passed!")

import matplotlib.pyplot as plt

def plot_gaussian(x, mu, sigma):
    # TODO: Use x, mu and sigma to calculate the probability density
    # function. Put the results in the y variable.
    # You can use your gaussian_density() function
    # from the first exercise.
    y = gaussian_density(x, mu, sigma)
    # TODO: Plot the results in a line chart. See the first example
    # in the pyplot tutorial for help:
    # https://matplotlib.org/xkcd/users/pyplot_tutorial.html
    plt.plot(x,y) #(x-value, y-value)
    plt.xlabel('x-variable')
    plt.ylabel('Probability density function')
    plt.title('Gaussian probability density function')
    plt.show()

    # Make sure to label the x axis, y axis and give the chart
    # a title.
    return None

# Run this code cell to see the results

x = np.linspace(0, 100, 200)
plot_gaussian(x, 50, 10)

"""
