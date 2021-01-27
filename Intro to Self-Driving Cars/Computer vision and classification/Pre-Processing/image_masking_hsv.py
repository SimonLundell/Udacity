import matplotlib.pyplot as plt
import matplotlib.image as mpimg

import numpy as np
import cv2

# Read in the image
image = mpimg.imread('images/car_green_screen2.jpg')

plt.imshow(image)

# Define our color selection boundaries in RGB values
lower_green = np.array([0,180,0])
upper_green = np.array([100,255,100])

# Define the masked area
mask = cv2.inRange(image, lower_green, upper_green)

# Mask the image to let the car show through
masked_image = np.copy(image)

masked_image[mask != 0] = [0, 0, 0]

# Display it!
plt.imshow(masked_image)

# Convert to HSV
hsv = cv2.cvtColor(image, cv2.COLOR_RGB2HSV)

# HSV channels
h = hsv[:,:,0]
s = hsv[:,:,1]
v = hsv[:,:,2]

# Visualize the individual color channels
f, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(20,10))
ax1.set_title('H channel')
ax1.imshow(h, cmap='gray')
ax2.set_title('S channel')
ax2.imshow(s, cmap='gray')
ax3.set_title('V channel')
ax3.imshow(v, cmap='gray')

# Defining the color selection boundaries in HSV values
lower_threshold = np.array([40,0,0])
upper_threshold = np.array([85,255,255])

# Applying the mask
mask = cv2.inRange(hsv, lower_threshold, upper_threshold) 

masked_hsv = np.copy(hsv)

# Setting fields not 0 to black
masked_hsv[mask != 0] = [0,0,0]

# Converting back to RGB
RGB_img = cv2.cvtColor(masked_hsv, cv2.COLOR_HSV2RGB)

plt.imshow(RGB_img)
plt.show()
