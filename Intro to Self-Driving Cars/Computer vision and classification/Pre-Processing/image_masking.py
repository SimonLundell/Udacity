import matplotlib.pyplot as plt
import matplotlib.image as mpimg

import numpy as np
import cv2

# Read in the image
image = mpimg.imread('images/car_green_screen.jpg')

# Print out the image dimensions (height, width, and depth (color))
print('Image dimensions:', image.shape)

# Display the image
plt.imshow(image)

# Define our color selection boundaries in RGB values
lower_green = np.array([0,180,0])
upper_green = np.array([100,255,100])

# Define the masked area
mask = cv2.inRange(image, lower_green, upper_green)

# Vizualize the mask
plt.imshow(mask, cmap='gray')

# Mask the image to let the car show through
masked_image = np.copy(image)

masked_image[mask != 0] = [0, 0, 0]

# Display it!
plt.imshow(masked_image)

# Load in a background image, and convert it to RGB
background_image = mpimg.imread('images/sky.jpg')

# Make background into same dimensions
resized_image = cv2.resize(background_image, (660, 450))

# Apply the reversed mask (replace all fields where mask == 0 with black)
masked_image2 = np.copy(resized_image)

masked_image2[mask == 0] = [0, 0, 0]

# Adding the 2 pictures together
combined = masked_image + masked_image2

plt.imshow(combined)
plt.show()
