import numpy as np
import matplotlib.image as mpimg  # for reading in images

import matplotlib.pyplot as plt
import cv2  # computer vision library

'%matplotlib qt' # This line to display the image interactively only works in Jupyter.

# Read in the image
image = mpimg.imread('images/waymo_car.jpg')

# Print out the image dimensions
print('Image dimensions:', image.shape)

# Change from color to grayscale
gray_image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)

# Renders the image, doesn't print it!
plt.imshow(gray_image, cmap='gray') 

# Prints the image
plt.show()

x = 400
y = 300

# Prints the color value of the pixel located in y, x
print(gray_image[y,x])

max_val = np.amax(gray_image)
min_val = np.amin(gray_image)

print('Max: ', max_val)
print('Min: ', min_val)

# Below just for fun

tiny_image = np.array([[0, 20, 30, 150, 120],
                      [200, 200, 250, 70, 3],
                      [50, 180, 85, 40, 90],
                      [240, 100, 50, 255, 10],
                      [30, 0, 75, 190, 220]])

plt.matshow(tiny_image, cmap='gray')
plt.show()
